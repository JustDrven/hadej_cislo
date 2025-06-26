#include "console.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void Console::clear() 
{
    cout << "\033[2J\033[H";
}

void Console::printLine(string str) 
{
    cout << str << endl;
}