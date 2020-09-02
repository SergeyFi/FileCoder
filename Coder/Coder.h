#pragma once

#include "ICoder.h"

#include <vector>

class Coder : public ICoder
{
    void EncodeFile(std::string filePath, std::string cipherPath, std::string keyPath) override;

    void DecodeFile(std::string filePath, std::string keyPath) override;
    
};
