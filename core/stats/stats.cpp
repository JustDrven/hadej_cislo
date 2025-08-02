/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#include "../../base.h"

#include "../../include/stats/stats.h"
#include "../../include/utils/strings.h"
#include "../../include/utils/console.h"
#include "../../include/settings.h"


#define STATS_FILE_NAME "stats.dat"

#define WINS_DISPLAY "Wins"
#define LOSSES_DISPLAY "Losses"


std::map<STAT_TYPE, int> stats;

bool exist()
{
    ISTREAM_T statsFile(STATS_FILE_NAME);

    return statsFile.good();
}


STR_T getNameByStatsType(STAT_TYPE _statType)
{
    if (_statType == Wins)
        return WINS_DISPLAY;

    return LOSSES_DISPLAY;
}

STAT_TYPE getStatsTypeByName(STR_T _statType)
{
    if (_statType == WINS_DISPLAY)
        return Wins;

    return Losses;
}

void Stats::Init()
{

    if (!exist())
    {
        OSTREAM_T statsFile(STATS_FILE_NAME);

        statsFile << WINS_DISPLAY << "=0" << std::endl;
        statsFile << LOSSES_DISPLAY << "=0";

        statsFile.close();
    }

    ISTREAM_T statsFile(STATS_FILE_NAME);
    STR_T line;

    while (LINES(statsFile, line))
    {
        if (line == "")
            continue;

        STRVEC_T data = string_util::Split(line, "=");

        stats.insert( { getStatsTypeByName(data.at(0)), std::stoi(data.at(1)) } );
    }

}

void Stats::PrintStats()
{
    Console::Clear();

    Console::PrintLine();
    Console::PrintLine(GSettings::LINE);
    Console::PrintLine();
    Console::PrintLine("Your stats:");
    Console::PrintLine("  - Wins: " + string_util::ToStr(GetStat(Wins)));
    Console::PrintLine("  - Losses: " + string_util::ToStr(GetStat(Losses)));
    Console::PrintLine();
    Console::PrintLine(GSettings::LINE);
    Console::PrintLine();

}

void Stats::Write(STAT_TYPE _statType)
{
    UINT oldValue = GetStat(_statType);
    stats.erase(_statType);

    stats.insert( { _statType, oldValue + 1 } );
}

UINT Stats::GetStat(STAT_TYPE _statType)
{
    return stats.at(_statType);
}

void Stats::Flush()
{
    OSTREAM_T statsFile(STATS_FILE_NAME);

    for (auto& p : stats)
        statsFile << getNameByStatsType(p.first) + "=" + string_util::ToStr(p.second) + "\n";

    statsFile.close();
}
