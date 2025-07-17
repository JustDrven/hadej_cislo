#pragma once

#include "../src/base.h"

namespace string_util {

    str_t toStr(int);
    bool isNumber(int);
    bool isDefine(int);
    str_t repeat(int, char);
    strvec_t split(str_t, str_t);

};
