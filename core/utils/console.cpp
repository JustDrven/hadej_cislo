/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#include "../../include/utils/console.h"

#include <iostream>

void Console::Clear()
{
    std::cout << "\033[2J\033[H";
}

void Console::PrintLine(STR_T str)
{
    std::cout << str << NL;
}