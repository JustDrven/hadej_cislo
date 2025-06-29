#include "player.h"

void Player::addCountOfGuess()
{
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

int Player::getCountOfGuesses()
{
    return this->count_of_guesses;
}