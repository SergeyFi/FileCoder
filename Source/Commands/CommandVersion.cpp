#include "CommandVersion.h"

#include <iostream>

void CommandVersion::Execute(std::vector<Modifier> modifiers)
{
    std::cout << "FileCoder Version: " << version << std::endl;
}
