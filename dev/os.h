#pragma once

#ifdef __WIN64 
    #define __START 1
#elif __WIN36
    #define __START 1
#elif __APPLE__
    #define __START 1
#elif __LINUX__
    #define __START 1
#else
    #define __START 0
#endif