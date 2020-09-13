#include "Command.h"

class CommandVersion : public Command
{
public:
    CommandVersion(std::string commandName,std::string newVersion)
    {
        name = commandName;
        version = newVersion;
    }

    void Execute(std::vector<Modifier> modifiers) override;

private:
    std::string version;
};
