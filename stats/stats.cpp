#include "../src/base.h"

#include "stats.h"
#include "../utils/strings.h"
#include "../utils/console.h"
#include "../src/settings.h"

#include <map>

#define STATS_FILE_NAME "stats.dat"

#define WINS_DISPLAY "Wins"
#define LOSSES_DISPLAY "Losses"


std::map<StatType, int> stats;

bool exist()
{
    istream_t statsFile(STATS_FILE_NAME);

    return statsFile.good();
}


str_t getNameByStatsType(StatType _statType)
{
    if (_statType == Wins)
        return WINS_DISPLAY;

    return LOSSES_DISPLAY;
}

StatType getStatsTypeByName(str_t _statType)
{
    if (_statType == WINS_DISPLAY)
        return Wins;

    return Losses;
}

void Stats::init()
{

    if (!exist())
    {
        ostream_t statsFile(STATS_FILE_NAME);

        statsFile << WINS_DISPLAY << "=0" << std::endl;
        statsFile << LOSSES_DISPLAY << "=0";

        statsFile.close();
    }

    istream_t statsFile(STATS_FILE_NAME);
    str_t line;

    while (std::getline(statsFile, line))
    {
        if (line == "")
            continue;

        strvec_t data = string_util::split(line, "=");

        stats.insert( { getStatsTypeByName(data.at(0)), std::stoi(data.at(1)) } );
    }

}

void Stats::printStats()
{
    Console::clear();

    Console::printLine();
    Console::printLine(GSettings::LINE);
    Console::printLine();
    Console::printLine("Your stats:");
    Console::printLine("  - Wins: " + string_util::toStr(getStat(Wins)));
    Console::printLine("  - Losses: " + string_util::toStr(getStat(Losses)));
    Console::printLine();
    Console::printLine(GSettings::LINE);
    Console::printLine();

}

void Stats::write(StatType _statType)
{
    int oldValue = getStat(_statType);
    stats.erase(_statType);

    stats.insert( { _statType, oldValue + 1 } );
}

int Stats::getStat(StatType _statType)
{
    return stats.at(_statType);
}

void Stats::flush()
{
    ostream_t statsFile(STATS_FILE_NAME);

    for (auto& p : stats)
        statsFile << getNameByStatsType(p.first) + "=" + string_util::toStr(p.second) + "\n";

    statsFile.close();
}
