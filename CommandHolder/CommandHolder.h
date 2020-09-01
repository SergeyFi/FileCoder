#pragma once

#include "ICommandHolder.h"

#include <unordered_map>

class CommandHolder : public ICommandHolder
{
public:

    ICommand* GetCommand(std::string commandName) override;

private:

    void AddNewCommand(std::string commandName,
                       std::function<ICommand *()> command) override;

    std::unordered_map<std::string, std::function<ICommand *()>> commands;
};
