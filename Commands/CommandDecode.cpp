#include "CommandDecode.h"

void CommandDecode::Execute(std::vector<Modifier> modifiers)
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

    bool b, c;
    b = !FileExist(cipherPath);
    c = !FileExist(keyPath);

    if (b || c)
    {
        return;
    }

    std::string prefix;
    if (needPrefix)
    {
        prefix = ".decoded";
    }

    PreparePath(filePath, RemovePrefix(cipherPath, ".cipher"), prefix);

    Coder->DecodeFile(cipherPath, filePath, keyPath);
}
