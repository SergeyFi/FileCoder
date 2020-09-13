#include "Logger.h"

#include "..//defination.h"
#include <iostream>
#include <cstdlib>

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

        for (auto& mod : command.modifiers)
        {
            std::cout << "Modifier: " << mod.modifier << " : ";

            for (auto& arg : mod.arguments)
            {
                std::cout << "Argument: " << arg << " ";
            }

            std::cout << std::endl;
        }
    }
}

void Logger::PrintPercent(std::string name, float percent)
{
    ClearScreen();
    std::cout << name << ": " << int(percent) << "%" << std::endl;
}

void Logger::ClearScreen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    std::system ("clear");
#endif
}
