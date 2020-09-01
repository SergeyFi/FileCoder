//#define DEBUG

#include <memory>

#include "Parser/Parser.h"
#include "Executor/Executor.h"


int main(int argc, char *argv[])
{
    std::shared_ptr<IParser> Parser {new class Parser()};
    std::shared_ptr<IExecutor> Executor {new class Executor()};

    Parser->Parse(argc, argv);

    Executor->ExecuteCommands(Parser->GetParsedCommands());

    return 0;
}
