#pragma once

#include <string>
#include <unordered_set>
#include <vector>

struct Modifier
{
    std::string modifier;
    std::vector<std::string> arguments;
};

struct CommandData
{
    std::string name;
    std::vector<Modifier> modifiers;
};