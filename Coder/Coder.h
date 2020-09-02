#pragma once

#include "ICoder.h"

#include <vector>

struct KeyCode
{
    char key;
    char code;
};

class Coder : public ICoder
{
    void EncodeFile(std::string filePath, std::string cipherPath, std::string keyPath) override;

    void DecodeFile(std::string filePath, std::string keyPath) override;

private:

    KeyCode Encode(char data);
    
};
