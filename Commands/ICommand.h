#pragma once

#include "../DataTypes/CommandData.h"

class ICommand
{
public:

    virtual void Execute(std::vector<Modifier> modifiers) = 0;

    virtual std::string GetName() = 0;
};