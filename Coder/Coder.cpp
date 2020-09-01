#include "Coder.h"

#include <fstream>

void Coder::CodeFile(std::string filePath, std::string cipherName, std::string keyName, std::string keyPath)
{
    std::ifstream file(filePath);

    std::string line;
    while (std::getline(file, line))
    {

    }
}

void Coder::EncodeFile(std::string filePath, std::string keyPath)
{

}
