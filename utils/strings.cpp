#include "strings.h"

#include <sstream>
#include <cctype>

std::string repeat(int _count, char _char)
{
    std::string str;

    for (int i = 0; i < _count; i++)
    {
        str += _char;
    }

    return str;
}

std::string toStr(int value)
{
    return std::to_string(value);
}

bool isNumber(int _ci)
{
    return std::isdigit(_ci) == 0;
}

bool isDefine(int _ci)
{
    return _ci != -1;
}