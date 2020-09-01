#include "Parser.h"

void Parser::Parse(int argc, char *argv[])
{
    bool nameMode = true;

    for (auto i = 1; i < argc; ++i)
    {
        std::string argument = argv[i];

        if (argument == ":")
        {
            nameMode = true;
            continue;
        }

        if (nameMode)
        {
            data.push_back({});
            data.back().name = argument;
            nameMode = false;
        }
        else if (argument[0] == '-')
        {
            data.back().modifiers.insert(argument);
        }
        else
        {
            data.back().arguments.emplace_back(argument);
        }
    }
}

std::vector<CommandData> Parser::GetParsedData()
{
    return data;
}
