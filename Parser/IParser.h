#pragma once

#include "../DataTypes/CommandData.h"

class IParser
{
public:

    virtual void Parse(int argc, char *argv[]) = 0;

    virtual std::vector<CommandData> GetParsedCommands() = 0;
};