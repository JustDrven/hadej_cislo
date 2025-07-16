#ifndef SETTINGS_H
#define SETTINGS_H

#include "../utils/strings.h"

class GSettings
{
    public:
        inline static int MAX_GUESS = 5;
        inline static std::string LINE = string_util::repeat(30, '=');
};

#endif
