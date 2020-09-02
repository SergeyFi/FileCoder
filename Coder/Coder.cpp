#include "Coder.h"

#include <fstream>
#include <bitset>
#include <iostream>

void Coder::EncodeFile(std::string filePath, std::string cipherPath, std::string keyPath)
{
    std::ifstream file(filePath, std::ios::binary | std::ios::out);

    std::ofstream fileCoded(cipherPath, std::ios::binary | std::ios::out);

    std::ofstream fileKey(keyPath, std::ios::binary | std::ios::in);

    const int bufferSize = 1024;

    std::vector<char> buffer (bufferSize + 1, 0);

    while (true)
    {
        file.read(buffer.data(), bufferSize);
        std::streamsize s = ((file) ? bufferSize : file.gcount());

        fileCoded.write(buffer.data(), s);

        if (!file)
        {
            break;
        }
    }
}

void Coder::DecodeFile(std::string filePath, std::string keyPath)
{

}

KeyCode Coder::Encode(char data)
{
    char key = 'a';
    char code = 'b';

    std::bitset<8> dataBin(data);
    std::bitset<8> keyGen;



    return {key, code};
}
