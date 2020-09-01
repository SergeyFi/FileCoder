#pragma once

#include "../Commands/ICommand.h"
#include "../DataTypes/CommandData.h"

#include <string>
#include <vector>
#include <functional>

class ICommandHolder
{
protected:

    virtual void AddNewCommand(std::string commandName,
                               std::function<ICommand*()> command) = 0;

public:

    template<class CommandClass, class ... CommandArguments>
    void AddCommand(const std::string& commandName, CommandArguments... args)
    {
        auto& commandConstructor = [commandName, args...]()
        {
            return new CommandClass(commandName, args...);
        };

        AddNewCommand(commandName, commandConstructor);
    }

    virtual ICommand* GetCommand(std::string commandName) = 0;
};
