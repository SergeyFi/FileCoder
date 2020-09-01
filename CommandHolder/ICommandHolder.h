#pragma once

#include "../Commands/ICommand.h"

#include <string>
#include <vector>

class ICommandHolder
{
public:

    template<class ... CommandArguments>
    void AddCommand()
    {

    }

    virtual ICommand GetCommand(std::string commandName) = 0;
};
