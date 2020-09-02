#pragma once

#include "ICoder.h"

#include <vector>

class Coder : public ICoder
{
    void CodeFile(std::string filePath, std::string cipherName, std::string cipherPath, std::string keyName,
                  std::string keyPath) override;

    void EncodeFile(std::string filePath, std::string keyPath) override;
    
};
