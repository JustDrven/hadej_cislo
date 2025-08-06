/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#pragma once

#include "../../base/precompile.h"

typedef enum
{
    Wins,
    Losses
} STAT_TYPE;

class Stats
{
public:
    STATIC void Init();
    STATIC void PrintStats();
    STATIC void Write(STAT_TYPE);
    STATIC UINT GetStat(STAT_TYPE);
    STATIC void Flush();
};
