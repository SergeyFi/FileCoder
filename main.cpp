//#define DEBUG

#include <memory>

#include "Parser/Parser.h"
#include "CommandHolder/CommandHolder.h"
#include "Executor/Executor.h"


int main(int argc, char *argv[])
{
    std::shared_ptr<IParser> Parser {new class Parser()};
    std::shared_ptr<ICommandHolder> CommandHolder {new class CommandHolder()};
    std::shared_ptr<IExecutor> Executor {new class Executor(CommandHolder.get())};

    Parser->Parse(argc, argv);

    Executor->ExecuteCommands(Parser->GetParsedCommands());

    return 0;
}
