#include "console.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void Console::clear_console() {
    cout << "\033[2J\033[H";
}

void Console::print_line(string str) {
    cout << str << endl;
}