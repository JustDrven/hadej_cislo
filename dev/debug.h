/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#pragma once

#define DEBUG 1

#if DEBUG == 1
    #include <iostream>

    #define LOG(str) std::cout << "[LOG] " str << std::endl;
    #define ERROR(str) std::cout << "[ERROR] " str << std::endl;
#elif
    #define LOG(str) 
    #define ERROR(str) 
#endif
