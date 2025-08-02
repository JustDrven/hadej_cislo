#pragma once

#include "../src/base.h"

typedef enum StatType {
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
