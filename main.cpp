#include "Parser/Parser.h"

#include <iostream>

int main(int argc, char *argv[])
{
    Parser parser;

    parser.Parse(argc, argv);

    for (auto& command : parser.GetParsedData())
    {
        std::cout << "Name: " << command.name << std::endl;

        for (auto& mod : command.modifiers)
        {
            std::cout << "Modifier: " << mod << std::endl;
        }

        for (auto& arg : command.arguments)
        {
            std::cout << "Argument: " << arg << std::endl;
        }
    }

    return 0;
}
