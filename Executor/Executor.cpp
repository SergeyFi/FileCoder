#include "Executor.h"

Executor::Executor(ICommandHolder* newCommandHolder)
{
    CommandHolder = newCommandHolder;
}

void Executor::ExecuteCommands(std::vector<CommandData> commandsData)
{
    for (const auto& data : commandsData)
    {
        auto* Command = CommandHolder->GetCommand(data.name);

        if (Command)
        {
            // Add argument and execute
        }
        else
        {
            // Error
        }
    }
}
