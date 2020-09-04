#include <memory>

#include "Parser/Parser.h"
#include "CommandHolder/CommandHolder.h"
#include "Executor/Executor.h"
#include "Coder/Coder.h"

#include "Commands/CommandVersion.h"
#include "Commands/CommandEncode.h"
#include "Commands/CommandDecode.h"


int main(int argc, char *argv[])
{
    std::shared_ptr<IParser> Parser {new class Parser()};
    std::shared_ptr<ICommandHolder> CommandHolder {new class CommandHolder()};
    std::shared_ptr<IExecutor> Executor {new class Executor(CommandHolder.get())};
    std::shared_ptr<ICoder> Coder {new class Coder()};

    CommandHolder->AddCommand<CommandVersion>("version", "0.1a");
    CommandHolder->AddCommand<CommandEncode>("encode", Coder.get());
    CommandHolder->AddCommand<CommandDecode>("decode", Coder.get());

    Parser->Parse(argc, argv);
    Executor->ExecuteCommands(Parser->GetParsedCommands());

    return 0;
}
