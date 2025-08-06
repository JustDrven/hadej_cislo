/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#pragma once

#define DEBUG 1

#if DEBUG == 1
#include <iostream>

#define LOG(str) std::cout << "[LOG] " str << NL;
#define ERROR(str) std::cout << "[ERROR] " str << NL;

#elif
#define LOG(str)
#define ERROR(str)
#endif
