#include "Coder.h"

#include <fstream>
#include <iostream>

void Coder::EncodeFile(std::string filePath, std::string cipherPath, std::string keyPath)
{
    std::ifstream file(filePath, std::ios::binary | std::ios::in);

    std::ofstream fileCoded(cipherPath, std::ios::binary | std::ios::out);

    std::ofstream fileKey(keyPath, std::ios::binary | std::ios::out);

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

void Coder::DecodeFile(std::string cipherPath, std::string filePath, std::string keyPath)
{
    std::ifstream  fileCoded(cipherPath, std::ios::binary | std::ios::out);

    std::ofstream file(filePath, std::ios::binary | std::ios::out);

    std::ifstream  fileKey(keyPath, std::ios::binary | std::ios::out);

    const int bufferSize = 1024;

    std::vector<char> cipherData (bufferSize + 1, 0);
    std::vector<char> keyData (bufferSize + 1, 0);

    while (true)
    {
        fileCoded.read(cipherData.data(), bufferSize);
        std::streamsize s = ((file) ? bufferSize : fileCoded.gcount());

        fileKey.read(keyData.data(), bufferSize);

        auto decodedData = Decode(cipherData, keyData);

        file.write(decodedData.data(), s);

        if (!file)
        {
            break;
        }
    }
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

std::vector<char> Coder::Decode(std::vector<char>& cipherData, std::vector<char> &keyData)
{
    std::vector<char> decodedData(cipherData.size());

    for (auto i = 0; i < cipherData.size(); ++i)
    {
        decodedData.push_back(static_cast<unsigned char>(cipherData[i]) ^ static_cast<unsigned char>(keyData[i]));
    }

    return decodedData;
}
