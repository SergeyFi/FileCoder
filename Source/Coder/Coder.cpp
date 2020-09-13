#include "Coder.h"

#include <fstream>
#include "../Logger/Logger.h"

void Coder::EncodeFile(std::string filePath, std::string cipherPath, std::string keyPath)
{
    std::ifstream file(filePath, std::ios::binary | std::ios::in);

    std::ofstream fileCoded(cipherPath, std::ios::binary | std::ios::out);

    std::ofstream fileKey(keyPath, std::ios::binary | std::ios::out);

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
            Logger::GetLogger()->Log("Finish file encoding.", LogType::notification);
            break;
        }
    }

    file.close();
    fileCoded.close();
    fileKey.close();
}

void Coder::DecodeFile(std::string cipherPath, std::string filePath, std::string keyPath)
{
    std::ifstream  fileCoded(cipherPath, std::ios::binary | std::ios::out);

    std::ofstream file(filePath, std::ios::binary | std::ios::out);

    std::ifstream  fileKey(keyPath, std::ios::binary | std::ios::out);

    std::vector<char> cipherData (bufferSize + 1, 0);
    std::vector<char> keyData (bufferSize + 1, 0);

    while (true)
    {
        fileCoded.read(cipherData.data(), bufferSize);
        fileKey.read(keyData.data(), bufferSize);
        std::streamsize s = ((fileKey) ? bufferSize : fileKey.gcount());

        auto decodedData = Decode(cipherData, keyData);

        file.write(decodedData.data(), s);

        if (!fileKey)
        {
            Logger::GetLogger()->Log("Finish file decoding.", LogType::notification);
            break;
        }
    }

    file.close();
    fileCoded.close();
    fileKey.close();
}

KeyCode Coder::Encode(std::vector<char>& data)
{
    std::vector<char> key;
    std::vector<char> dataEncoded;

    for (auto dataChar : data)
    {
        unsigned char randomChar = RandGenerator->GetNextRandomChar();

        key.push_back(randomChar);
        dataEncoded.push_back(static_cast<unsigned char>(dataChar) ^ randomChar);
    }

    return {key, dataEncoded};
}

std::vector<char> Coder::Decode(std::vector<char>& cipherData, std::vector<char> &keyData)
{
    std::vector<char> decodedData;

    for (auto i = 0; i < cipherData.size(); ++i)
    {
        decodedData.push_back(static_cast<unsigned char>(cipherData[i]) ^ static_cast<unsigned char>(keyData[i]));
    }

    return decodedData;
}
