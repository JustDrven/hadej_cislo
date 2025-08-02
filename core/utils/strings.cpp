/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/


#include "../../include/utils/strings.h"

#include <sstream>
#include <cctype>

STR_T string_util::Repeat(UINT _count, char _char)
{
    STR_T str;

    for (int i = 0; i < _count; i++)
    {
        str += _char;
    }

    return str;
}

STR_T string_util::ToStr(int value)
{
    return std::to_string(value);
}

bool string_util::IsNumber(int _ci)
{
    return std::isdigit(_ci) == 0;
}

bool string_util::IsDefine(int _ci)
{
    return _ci != -1;
}

STRVEC_T string_util::Split(STR_T s, STR_T delimiter) 
{
    STRVEC_T tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);

    while (end != STR_T::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find(delimiter, start);
    }

    tokens.push_back(s.substr(start));
    
    return tokens;  
}
