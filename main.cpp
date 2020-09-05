#include "Initialization.h"

int main(int argc, char *argv[])
{
    Init();

    Parser->Parse(argc, argv);
    Executor->ExecuteCommands(Parser->GetParsedCommands());

    return 0;
}
