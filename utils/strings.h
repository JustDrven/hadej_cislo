#ifndef STRINGS_UTIL_H
#define STRINGS_UTIL_H

#include <string>
#include <vector>

namespace string_util {


    std::string toStr(int);
    bool isNumber(int);
    bool isDefine(int);
    std::string repeat(int, char);
    std::vector<std::string> split(std::string, std::string);

};

#endif
