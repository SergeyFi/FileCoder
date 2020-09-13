#include "CommandHolder.h"

ICommand *CommandHolder::GetCommand(std::string commandName)
{
    if (commands.count(commandName) > 0)
    {
        return commands[commandName]();
    }

    return nullptr;
}

void CommandHolder::AddNewCommand(std::string commandName,
                                  std::function<ICommand *()> command)
{
    commands[std::move(commandName)] = std::move(command);
}
