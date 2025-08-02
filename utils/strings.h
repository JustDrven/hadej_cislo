#pragma once

#include "../src/base.h"

namespace string_util {

    STR_T ToStr(int);
    bool IsNumber(int);
    bool IsDefine(int);
    STR_T Repeat(UINT, char);
    STRVEC_T Split(STR_T, STR_T);

};
