#pragma once

#include "Command.h"
#include "../Coder/ICoder.h"

class CommandEncode : public Command
{
public:
    CommandEncode(std::string newName,ICoder* NewCoder)
    {
        name = std::move(newName);
        Coder = NewCoder;
    }

    void Execute(std::vector<Modifier> modifiers) override;

private:

    ICoder* Coder;
};
