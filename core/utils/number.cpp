/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#include "../../include/utils/number.h"
#include "../../base/precompile.h"

#include <random>

bool number_util::IsBigger(int _v1, int _v2)
{
    return _v1 > _v2;
}

int number_util::GetRandom(int _mi, int _ma)
{
    STATIC std::random_device rd;
    STATIC std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(_mi, _ma);

    return dist(gen);
}