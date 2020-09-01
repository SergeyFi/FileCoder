#pragma once

#include <string>
#include <unordered_set>

struct CommandFullName
{
    std::string name;
    std::unordered_set<std::string> modifiers;
};