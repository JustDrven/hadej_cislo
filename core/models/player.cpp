/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#include "../../include/models/player.h"
#include "../../include/settings.h"

void Player::AddCountOfGuess()
{
    if (this->count_of_guesses > GSettings::MAX_GUESS)
        return;

    this->count_of_guesses++;
}

void Player::SetYourNumber(int _yn)
{
    this->your_number = _yn;
}

void Player::SetYourGuess(int _yg)
{
    this->your_guess = _yg;
}

int Player::GetYourNumber()
{
    return this->your_number;
}

int Player::GetYourGuess()
{
    return this->your_guess;
}

UINT Player::GetCountOfGuesses()
{
    return this->count_of_guesses;
}