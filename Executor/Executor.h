#pragma once

#include "IExecutor.h"

class Executor : public IExecutor
{
public:
    void ExecuteCommands(std::vector<CommandData> commandsData) override;
};
