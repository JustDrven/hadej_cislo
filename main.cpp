#include "src/game.h"

#include <string>
#include <cctype>

int main(int argc, char const *argv[])
{

    Game game;

    bool genRanNum = false;
    if (argc == 2)
    {
        std::string randomArg = argv[1];

        std::transform(randomArg.begin(), randomArg.end(), randomArg.begin(),
            [](unsigned char c) { return std::tolower(c); });


        if (randomArg == "random")
            genRanNum = true;
    }
    

    game.start(genRanNum);

    return 0;
}
