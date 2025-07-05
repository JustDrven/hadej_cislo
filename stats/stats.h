#ifndef STATS_H
#define STATS_H

#include <string>

enum StatType {
    Wins,
    Losses
};

class Stats
{
    public:
        static void init();
        static void write(StatType _statType);
        static int getStat(StatType _statType);
        static std::string getStatFormat(StatType _statType);
        static void flush();
};

#endif