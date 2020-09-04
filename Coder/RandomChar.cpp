#include "RandomChar.h"

#include <string>
#include <iostream>

unsigned char RandomChar::GetNextRandomChar()
{
    if (randomChars.empty())
    {
        AddRandCharsToQueue();
    }

    char front = randomChars.front();
    randomChars.pop();

    return front;
}

void RandomChar::AddRandCharsToQueue()
{
    unsigned int randomNumber = gen();

    std::string numberStr = std::to_string(randomNumber);

    std::string triplet;
    for (auto i = 0; i < numberStr.size(); ++i)
    {
        if (i%3 == 0 && i != 0)
        {
            randomChars.push(std::stoi(triplet));
            triplet.clear();
        }

        triplet += numberStr[i];
    }
}
