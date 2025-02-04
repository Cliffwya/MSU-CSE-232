//wordList.h
#pragma once
#include <string>

bool AtListPosition(const std::string & string_list, const std::string & single_string, size_t pos);
size_t FindInList(const std::string & string_list, const std::string & single_string, size_t pos);
std::string GetFirstInList(const std::string & word_list, std::string * word1, std::string * word2);
size_t CountInList(const std::string & word_list, const std::string & single_string);