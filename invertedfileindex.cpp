#include "invertedfileindex.h"

std::string getInvertedFileIndexAsCsv(const std::string& str)
{
    std::regex commonWords(R"((a|an|the|and|or|but|i|me|my|you|your|he|him|his|she|her|it|its|we|us|our|they|their|them))");
    uint64_t wordCounter = 0;
    std::istringstream lineReader(str);
    std::map<std::string, std::list<uint64_t>> index;
    while (!lineReader.eof())
    {
        std::string line;
        std::getline(lineReader, line, '\n');
        std::istringstream wordReader(line);
        while (!wordReader.eof())
        {
            std::string word;
            std::getline(wordReader, word, ' ');
            if (!word.empty())
            {
                if (ispunct(word.back()) && word.back() != '\'') word.pop_back();
                word = toAllLower(word);
                if (!std::regex_match(word, commonWords))
                {
                    if (!index.contains(word))
                    {
                        index.insert({word, std::list<uint64_t>(1, wordCounter)});
                    }
                    else
                    {
                        index[word].push_back(wordCounter);
                    }
                }
                wordCounter++;
            }
        }
    }
    std::string result;
    for (auto& kv: index)
    {
        result += kv.first;
        for (auto& n : kv.second)
        {
            result += "," + std::to_string(n);
        }
        result += "\n";
    }
    return result;
}

std::string toAllLower(std::string str)
{
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        str[i] = static_cast<char>(tolower(str[i]));
    }
    return str;
}