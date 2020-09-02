#pragma once

#include <string>

class ICoder
{
    virtual void CodeFile(std::string filePath, std::string cipherName, std::string cipherPath, std::string keyName,
                          std::string keyPath) = 0;

    virtual void EncodeFile(std::string filePath, std::string keyPath) = 0;
};