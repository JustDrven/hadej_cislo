#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

using namespace std;

class Console
{
    public:
        static void clear_console();
        static void print_line(string str = "");
};


#endif
