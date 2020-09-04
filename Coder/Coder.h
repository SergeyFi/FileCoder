#pragma once

#include "ICoder.h"

#include <vector>
#include <bitset>

struct KeyCode
{
    std::vector<char> key;
    std::vector<char> dataEncoded;
};

class Coder : public ICoder
{
    void EncodeFile(std::string filePath, std::string cipherPath, std::string keyPath) override;

    void DecodeFile(std::string filePath, std::string keyPath) override;

private:

    KeyCode Encode(std::vector<char>& data);
    
};
