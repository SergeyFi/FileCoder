#include "Parser.h"

void Parser::Parse(int argc, char *argv[])
{
    const std::string nextCommandSymbol = ":";

    bool nameMode = true;
    bool modMode = false;
    bool argMode = false;

    for (auto i = 1; i < argc; ++i)
    {
        std::string argument = argv[i];

        if (argument == nextCommandSymbol)
        {
            nameMode = true;
            modMode = false;
            continue;
        }

        if (nameMode)
        {
            data.push_back({});
            data.back().name = argument;
            nameMode = false;
            continue;
        }

        if (argument[0] == '-')
        {
            modMode = true;
            argMode = false;
        }

        if (modMode)
        {
            data.back().modifiers.push_back({});
            data.back().modifiers.back().modifier = argument;
            modMode = false;
            argMode = true;
            continue;
        }

        if (argMode)
        {
            data.back().modifiers.back().arguments.push_back(argument);
        }
    }
}

std::vector<CommandData> Parser::GetParsedCommands()
{
    return data;
}
