#pragma once

#include "../DataTypes/CommandData.h"

class IExecutor
{
public:
    virtual void ExecuteCommands(std::vector<CommandData> commandsData) = 0;
};