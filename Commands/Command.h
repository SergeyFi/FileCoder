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
};

