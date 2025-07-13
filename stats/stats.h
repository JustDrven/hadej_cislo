#ifndef STATS_H
#define STATS_H

enum StatType {
    Wins,
    Losses
};

class Stats
{
    public:
        static void init();
        static void printStats();
        static void write(StatType);
        static int getStat(StatType);
        static void flush();
};

#endif