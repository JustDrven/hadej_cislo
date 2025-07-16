#include "strings.h"

#include <sstream>
#include <cctype>
#include <vector>

std::string string_util::repeat(int _count, char _char)
{
    std::string str;

    for (int i = 0; i < _count; i++)
    {
        str += _char;
    }

    return str;
}

std::string string_util::toStr(int value)
{
    return std::to_string(value);
}

bool string_util::isNumber(int _ci)
{
    return std::isdigit(_ci) == 0;
}

bool string_util::isDefine(int _ci)
{
    return _ci != -1;
}

std::vector<std::string> string_util::split(std::string s, std::string delimiter) 
{
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find(delimiter, start);
    }

    tokens.push_back(s.substr(start));
    
    return tokens;  
}
