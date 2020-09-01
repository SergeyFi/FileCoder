#pragma once

#include <string>
#include <unordered_set>
#include <vector>

struct CommandData
{
    std::string name;
    std::unordered_set<std::string> modifiers;
    std::vector<std::string> arguments;
};