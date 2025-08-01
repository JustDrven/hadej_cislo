#include "player.h"
#include "../settings.h"

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

unsigned int Player::GetCountOfGuesses()
{
    return this->count_of_guesses;
}