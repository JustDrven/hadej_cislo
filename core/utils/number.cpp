/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/


#include "../../include/utils/number.h"
#include <random>

bool number_util::IsBigger(int _v1, int _v2)
{
    return _v1 > _v2;
}

int number_util::GetRandom(int _mi, int _ma)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(_mi, _ma);

    return dist(gen);
}