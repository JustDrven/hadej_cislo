#ifndef GAME_H
#define GAME_H

#include "models/player.h"

class Game
{

    private:
        Player basePlayer{};

    public:
        void start(bool);
        void win();
        void end();

        bool canWin();
        bool checkEnd();

        void setYourNumber();
        void shutdown();

        Player* getPlayer();

        
};

#endif