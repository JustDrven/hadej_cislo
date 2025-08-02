/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#pragma once

#include "../../base.h"

class Player
{
    protected:
        UINT count_of_guesses = 0;
        int your_number = -1;
        int your_guess = -1;

    public:
        unsigned int GetCountOfGuesses();
        int GetYourNumber();
        int GetYourGuess();

        void AddCountOfGuess();
        void SetYourGuess(int);
        void SetYourNumber(int);
};
