#pragma once

#include "ICommand.h"
#include "../Logger/Logger.h"


class Command : public ICommand
{
public:
    std::string GetName() override;

protected:

    std::string name;

    bool PathExist(std::string path);

    bool FileExist(std::string path);

    bool IsDirectory(std::string path);

    std::string GetFileName(std::string path);

    void PreparePath(std::string& path, std::string pathReserve, std::string prefix);

    std::string RemovePrefix(const std::string& path, std::string prefix);

    std::string GetArgument(const Modifier& modifier, int index);
};

