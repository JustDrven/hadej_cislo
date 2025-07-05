#ifndef STRINGS_UTIL_H
#define STRINGS_UTIL_H

#include <string>
#include <vector>

std::string toStr(int value);
bool isNumber(int _ci);
bool isDefine(int _ci);
std::string repeat(int _count, char _char);
std::vector<std::string> split(std::string s, std::string delimiter);

#endif