#include "console.h"

#include <iostream>

void Console::clear() 
{
    std::cout << "\033[2J\033[H";
}

void Console::printLine(str_t str) 
{
    std::cout << str << std::endl;
}