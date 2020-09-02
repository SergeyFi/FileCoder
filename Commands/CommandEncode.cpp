#include "CommandEncode.h"

void CommandEncode::Execute(std::vector<Modifier> modifiers)
{
    std::string filePath, cipherPath, keyPath;

    for (const auto& modifier : modifiers)
    {
        if (modifier.arguments.empty())
        {
            break;
        }

        if (modifier.modifier == "-F")
        {
            filePath = modifier.arguments[0];
        }
        else if (modifier.modifier == "-C")
        {
            cipherPath = modifier.arguments[0];
        }
        else if (modifier.modifier == "-C")
        {
            keyPath = modifier.arguments[0];
        }
    }

    Coder->EncodeFile(filePath, cipherPath, keyPath);
}
