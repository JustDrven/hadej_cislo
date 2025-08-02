/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#include "../include/game.h"
#include "../include/stats/stats.h"

#include "../dev/debug.h"
#include "../dev/os.h"

#include "precompile.h"

int main(int argc, char const *argv[])
{

    if (__START != 1) {
        LOG("Neznámý operační systém.");
        
        return 1;
    }

    Stats::Init();

    Game game;

    bool genRanNum = false;
    if (argc == 2)
    {
        STR_T randomArg = argv[1];

        std::transform(randomArg.begin(), randomArg.end(), randomArg.begin(),
            [](unsigned char c) { return std::tolower(c); });

        if (randomArg == "stats")
        {
            Stats::PrintStats();
            return 0;
        }

        if (randomArg == "random")
            genRanNum = true;
    }
    

    game.Start(genRanNum);

    return 0;
}
