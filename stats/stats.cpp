#include "stats.h"
#include <fstream>
#include <string>
#include <map>

#define STATS_FILE_NAME "stats.dat"


using namespace std;

map<StatType, int> data;

void Stats::init()
{

    
    write(Wins);
    write(Losses);

}

void Stats::write(StatType _statType)
{
}

int Stats::getStat(StatType _statType)
{
    fstream statFile(STATS_FILE_NAME);


    string statName = getStatFormat(_statType);
    string line;
    while (getline(statFile, line)) {
        if (line.rfind(statName, 0) == 0) {
            return 1;
        }
    }

    return 0;
}

string Stats::getStatFormat(StatType _statType)
{
    switch (_statType)
    {
    case Wins:
        return "Wins";
    
    case Losses:
        return "Losses";
    }

    return "Unknown";
}

void Stats::flush() {
    ofstream statsFile(STATS_FILE_NAME);

    statsFile << "Heloo";


    statsFile.close();
}