#pragma once

#include "ILogger.h"
#include <unordered_map>

class Logger: public ILogger
{
public:
    void Log(std::string text, LogType logType) override;

    void PrintCommandDebug(const std::vector<CommandData> &data) override;

    static ILogger* GetLogger()
    {
        static ILogger* Logger = new class Logger();

        return Logger;
    }

private:

    const std::unordered_map<LogType, std::string> textLogType
            {
                    {LogType::notification, "Notification"},
                    {LogType::warning, "Warning"},
                    {LogType::error, "Error"}
            };

    Logger() = default;
};
