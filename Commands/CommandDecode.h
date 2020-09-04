#include "Command.h"
#include "../Coder/ICoder.h"

class CommandDecode : public Command
{
public:
    CommandDecode(std::string newName,ICoder* NewCoder)
    {
        name = std::move(newName);
        Coder = NewCoder;
    }

    void Execute(std::vector<Modifier> modifiers) override;

private:

    ICoder* Coder;
};
