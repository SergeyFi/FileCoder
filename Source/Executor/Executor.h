#pragma once

#include "IExecutor.h"
#include "../CommandHolder/ICommandHolder.h"

class Executor : public IExecutor
{
public:
    Executor(ICommandHolder* newCommandHolder);

    void ExecuteCommands(std::vector<CommandData> commandsData) override;

private:

    ICommandHolder* CommandHolder;
};
