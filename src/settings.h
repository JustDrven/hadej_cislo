#pragma once

#include "../utils/strings.h"
#include "./base.h"

class GSettings
{
    public:
        inline static int MAX_GUESS = 5;
        inline static str_t LINE = string_util::repeat(30, '=');
};
