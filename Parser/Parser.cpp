#include "Parser.h"

void Parser::Parse(int argc, char *argv[])
{
    bool nameMode = true;
    bool specifierMode = false;
    bool argumentMode = false;

    for (auto i = 0; i < argc; ++i)
    {
        auto& argument = argv[i];

        CommandData newCommandData;

        if (nameMode)
        {
            newCommandData.name = argument;
            nameMode = false;
            specifierMode = true;
        }

        if (specifierMode)
        {
            if (argument[0] == '-')
            {
                newCommandData.modifiers.insert(argument);
            }
            else
            {
                specifierMode = false;
                argumentMode = true;
            }
        }

        if (argumentMode)
        {
            if (argument[0] == '"' && argument[std::strlen(argument) - 1])
            {
                newCommandData.arguments.emplace_back(argument);
            }
            else
            {
                data.push_back(newCommandData);
                newCommandData = CommandData();

                newCommandData.name = argument;

                specifierMode = true;
                argumentMode = false;
            }
        }
    }
}

std::vector<CommandData> Parser::GetParsedData()
{
    return data;
}
