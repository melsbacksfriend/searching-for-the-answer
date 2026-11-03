#ifndef INVERTEDFILEINDEX_H
#define INVERTEDFILEINDEX_H
#include <string>
#include <map>
#include <cstdint>
#include <cctype>
#include <regex>
#include <sstream>
#include <list>

std::string getInvertedFileIndexAsCsv(const std::string& str);

std::string toAllLower(std::string str);

#endif // INVERTEDFILEINDEX_H
