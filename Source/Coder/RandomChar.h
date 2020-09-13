#pragma once

#include "IRandomChar.h"

#include <queue>
#include <random>

class RandomChar : public IRandomChar
{
public:

    unsigned char GetNextRandomChar() override;

private:
    std::queue<unsigned char> randomChars;

    void AddRandCharsToQueue();



    std::random_device gen;
};
