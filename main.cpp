#include <iostream>

#include "src/factorial.hpp"
#include "invertedfileindex.h"
#include <fstream>
#include <filesystem>

int main()
{
    std::cout << "Please enter the path to an existing file: ";
    std::string inPath;
    std::getline(std::cin, inPath, '\n');
    std::cout << "Please enter the path to the location you want to save the .csv to: ";
    std::string outPath;
    std::getline(std::cin, outPath, '\n');
    if (!std::filesystem::is_regular_file(inPath))
    {
        std::cerr << "The input file must exist!\n";
        return -1;
    }
    uint64_t fileSize = std::filesystem::file_size(inPath);
    std::string inFileContent(fileSize, '\0');
    std::ifstream in(inPath);
    in.read(inFileContent.data(), inFileContent.length());
    in.close();
    std::string outFileContent = getInvertedFileIndexAsCsv(inFileContent);
    std::ofstream out(outPath);
    out.write(outFileContent.data(), outFileContent.length());
    out.close();
    return 0;
}
