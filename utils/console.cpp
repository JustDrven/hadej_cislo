#include "console.h"

#include <iostream>
#include <string>

void Console::clear() 
{
    std::cout << "\033[2J\033[H";
}

void Console::printLine(string str) 
{
    std::cout << str << std::endl;
}