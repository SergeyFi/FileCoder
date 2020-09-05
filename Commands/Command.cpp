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

    return pathExist;
}

bool Command::FileExist(std::string path)
{
    std::error_code error;
    bool fileExist = std::filesystem::is_regular_file(path, error);

    if (!fileExist)
    {
        Logger::GetLogger()->Log("File " + path + " does not exist !", LogType::error);
    }

    return fileExist;
}

bool Command::IsDirectory(std::string path)
{
    std::error_code error;
    bool isDirectory = std::filesystem::is_directory(path, error);

    return isDirectory;
}

std::string Command::GetFileName(std::string path)
{
    return std::filesystem::path(path).filename().string();
}

void Command::PreparePath(std::string& path, std::string pathReserve, std::string prefix)
{
    if (path.empty())
    {
        path = pathReserve;
    }

    if (IsDirectory(path))
    {
        path += GetFileName(pathReserve);
    }

    path +=  prefix;
}

std::string Command::RemovePrefix(const std::string &path, std::string prefix)
{
    std::string newPath = path;

    size_t pos = newPath.find(prefix);
    if (pos != std::string::npos)
    {
        newPath.erase(pos, prefix.length());
    }

    return newPath;
}

std::string Command::GetArgument(const Modifier& modifier, int index)
{
    if (modifier.arguments.size() <= index)
    {
        return "";
    }

    return modifier.arguments[index];
}
