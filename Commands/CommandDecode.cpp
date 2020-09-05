#include "CommandDecode.h"

void CommandDecode::Execute(std::vector<Modifier> modifiers)
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
        else if (modifier.modifier == "-K")
        {
            keyPath = modifier.arguments[0];
        }
    }

    bool b, c;

    b = !FileExist(cipherPath);
    c = !FileExist(keyPath);

    if (b || c)
    {
        return;
    }

    Coder->DecodeFile(cipherPath, filePath, keyPath);
}
