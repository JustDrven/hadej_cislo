#include "strings.h"

#include <sstream>
#include <cctype>

str_t string_util::repeat(int _count, char _char)
{
    str_t str;

    for (int i = 0; i < _count; i++)
    {
        str += _char;
    }

    return str;
}

str_t string_util::toStr(int value)
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

strvec_t string_util::split(str_t s, str_t delimiter) 
{
    strvec_t tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);

    while (end != str_t::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find(delimiter, start);
    }

    tokens.push_back(s.substr(start));
    
    return tokens;  
}
