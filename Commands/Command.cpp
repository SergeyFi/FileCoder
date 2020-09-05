#include "Command.h"

#include <filesystem>
#include "../Logger/Logger.h"

std::string Command::GetName()
{
    return name;
}

bool Command::PathExist(std::string path)
{
    std::error_code error;
    bool pathExist = std::filesystem::exists(path, error);

    if (!pathExist)
    {
        Logger::GetLogger()->Log(error.message(), LogType::error);
    }

    return pathExist;
}

bool Command::FileExist(std::string path)
{
    std::error_code error;
    bool fileExist = std::filesystem::is_regular_file(path, error);

    if (!fileExist)
    {
        Logger::GetLogger()->Log(error.message(), LogType::error);
    }

    return fileExist;
}
