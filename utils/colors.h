#ifndef COLOR_BASE_H
#define COLOR_BASE_H

#include <string>

using namespace std;

class ColorBase
{
    public:
        inline static string GREEN = "\033[32m";
        inline static string RED = "\033[31m";
        inline static string RESET = "\033[37m";
};

#endif
