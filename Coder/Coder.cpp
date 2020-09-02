#include "Coder.h"

#include <fstream>

void Coder::EncodeFile(std::string filePath, std::string cipherPath, std::string keyPath)
{
    std::ifstream file(filePath, std::ios::binary | std::ios::out);

    std::ofstream fileCoded(keyPath, std::ios::binary | std::ios::in);

    std::string data;
    while (std::getline(file, data))
    {
        fileCoded << data;
    }
}

void Coder::DecodeFile(std::string filePath, std::string keyPath)
{

}
