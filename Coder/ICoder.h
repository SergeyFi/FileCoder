#pragma once

#include <string>

class ICoder
{

public:
    virtual void EncodeFile(std::string filePath, std::string cipherPath, std::string keyPath) = 0;

    virtual void DecodeFile(std::string filePath, std::string keyPath) = 0;
};