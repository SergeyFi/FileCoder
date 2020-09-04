#include "Coder.h"

#include <fstream>
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

        KeyCode keyCodePair = Encode(buffer);

        fileCoded.write(keyCodePair.dataEncoded.data(), s);
        fileKey.write(keyCodePair.key.data(), s);

        if (!file)
        {
            break;
        }
    }
}

void Coder::DecodeFile(std::string filePath, std::string keyPath)
{

}

KeyCode Coder::Encode(std::vector<char>& data)
{
    std::vector<char> key;
    std::vector<char> dataEncoded;

    for (auto dataChar : data)
    {
        // Random generator of char must be here,
        unsigned char randomChar = 'r';

        key.push_back(randomChar);
        dataEncoded.push_back(static_cast<unsigned char>(dataChar) ^ randomChar);
    }

    return {key, dataEncoded};
}
