#include "src/game.h"
#include "stats/stats.h"

#include <string>

int main(int argc, char const *argv[])
{

    Stats::init();

    Game game;

    bool genRanNum = false;
    if (argc == 2)
    {
        std::string randomArg = argv[1];

        std::transform(randomArg.begin(), randomArg.end(), randomArg.begin(),
            [](unsigned char c) { return std::tolower(c); });

        if (randomArg == "stats")
        {
            Stats::printStats();
            return 0;
        }

        if (randomArg == "random")
            genRanNum = true;
    }
    

    game.start(genRanNum);

    return 0;
}
