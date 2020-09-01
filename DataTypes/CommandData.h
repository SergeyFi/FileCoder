#pragma once

#include <string>
#include <unordered_set>
#include <vector>

struct CommandArguments
{
    std::unordered_set<std::string> modifiers;
    std::vector<std::string> arguments;
};

struct CommandData
{
    std::string name;
    CommandArguments arguments;
};