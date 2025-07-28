#pragma once

#include "models/player.h"

class Game
{

    private:
        Player base_player{};

    public:
        void Start(bool);
        void Win();
        void End();

        bool CanWin();
        bool CheckEnd();

        void SetYourNumber();
        void Shutdown();

        Player& GetPlayer();

        
};
