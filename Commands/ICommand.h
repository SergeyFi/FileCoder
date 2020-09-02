#pragma once

#include "../DataTypes/CommandData.h"

class ICommand
{
public:

    virtual void Execute(CommandArguments arguments) = 0;
};