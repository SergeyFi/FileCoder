#include "CommandEncode.h"

void CommandEncode::Execute(std::vector<Modifier> modifiers)
{
    std::string filePath, cipherPath, keyPath;
    bool needPrefix = false;

    for (const auto& modifier : modifiers)
    {
        if (modifier.modifier == "-F")
        {
            filePath = GetArgument(modifier, 0);
        }
        else if (modifier.modifier == "-C")
        {
            cipherPath = GetArgument(modifier, 0);
        }
        else if (modifier.modifier == "-K")
        {
            keyPath = GetArgument(modifier, 0);
        }
        else if (modifier.modifier == "-P")
        {
            needPrefix = true;
        }
    }

    if (!FileExist(filePath))
    {
        return;
    }

    std::string keyPrefix;
    std::string cipherPrefix;

    if (needPrefix || keyPath.empty())
    {
        keyPrefix = ".key";
        cipherPrefix = ".cipher";
    }

    if (needPrefix || cipherPath.empty())
    {
        cipherPrefix = ".cipher";
    }

    PreparePath(keyPath, filePath, keyPrefix);
    PreparePath(cipherPath, filePath, cipherPrefix);

    Coder->EncodeFile(filePath, cipherPath, keyPath);
}
