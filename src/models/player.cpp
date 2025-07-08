#include "player.h"
#include "../settings.h"

void Player::addCountOfGuess()
{
    if (this->count_of_guesses > GSettings::MAX_GUESS)
        return;

    this->count_of_guesses++;
}

void Player::setYourNumber(int _yn)
{
    this->your_number = _yn;
}

void Player::setYourGuess(int _yg)
{
    this->your_guess = _yg;
}

int Player::getYourNumber()
{
    return this->your_number;
}

int Player::getYourGuess()
{
    return this->your_guess;
}

unsigned int Player::getCountOfGuesses()
{
    return this->count_of_guesses;
}