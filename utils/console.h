#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

using namespace std;

class Console
{
    public:
        static void clear();
        static void printLine(string str = "");
};


#endif
