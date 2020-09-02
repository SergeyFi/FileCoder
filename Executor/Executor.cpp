//#define DEBUG

#include "Executor.h"
#include "../Logger/Logger.h"

Executor::Executor(ICommandHolder* newCommandHolder)
{
    CommandHolder = newCommandHolder;
}

void Executor::ExecuteCommands(std::vector<CommandData> commandsData)
{

#ifdef DEBUG
    Logger::GetLogger()->PrintCommandDebug(commandsData);
#endif

    for (const auto& data : commandsData)
    {
        auto* Command = CommandHolder->GetCommand(data.name);

        if (Command)
        {
            Command->Execute(data.modifiers);
        }
        else
        {
            Logger::GetLogger()->Log("Unknown command: " + data.name, LogType::error);
            break;
        }
    }
}
