#pragma once

#include "../utils/strings.h"
#include "./base.h"

class GSettings
{
    public:
        ISTATIC int MAX_GUESS = 5;
        ISTATIC STR_T LINE = string_util::Repeat(30, '=');
};
