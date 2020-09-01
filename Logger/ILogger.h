#pragma once

#include "../DataTypes/CommandData.h"
#include "Logger.h"

#include <string>
#include <vector>


enum class LogType
{
    notification,
    warning,
    error
};

class ILogger
{
public:

    virtual void Log(std::string text, LogType logType) = 0;

    virtual void PrintCommandDebug(const std::vector<CommandData>& data) = 0;
};