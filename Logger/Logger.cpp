#include "Logger.h"

#include <iostream>

void Logger::Log(std::string text, LogType logType)
{
    std::cout << textLogType.find(logType)->second << ": " << text << std::endl;
}

void Logger::PrintCommandDebug(const std::vector<CommandData> &data)
{
    Log("Commands: ", LogType::notification);

    for (auto& command : data)
    {
        std::cout << "Name: " << command.name << std::endl;

        for (auto& mod : command.arguments.modifiers)
        {
            std::cout << "Modifier: " << mod << std::endl;
        }

        for (auto& arg : command.arguments.arguments)
        {
            std::cout << "Argument: " << arg << std::endl;
        }
    }
}
