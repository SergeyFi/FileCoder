#pragma once

#include "IParser.h"

class Parser : public IParser
{

public:
    void Parse(int argc, char *argv[]) override;

    std::vector<CommandData> GetParsedData() override;

private:

    std::vector<CommandData> data;
};
