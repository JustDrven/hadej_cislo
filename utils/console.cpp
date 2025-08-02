#include "console.h"

#include <iostream>

void Console::Clear() 
{
    std::cout << "\033[2J\033[H";
}

void Console::PrintLine(STR_T str) 
{
    std::cout << str << std::endl;
}