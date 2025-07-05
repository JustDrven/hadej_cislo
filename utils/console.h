#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

class Console
{
    public:
        static void clear();
        static void printLine(std::string str = "");
};


#endif
