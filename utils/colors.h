#pragma once

#include <string>

class ColorBase
{
    public:
        inline static std::string GREEN = "\033[32m";
        inline static std::string RED = "\033[31m";
        inline static std::string RESET = "\033[37m";
};
