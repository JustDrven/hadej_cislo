#pragma once

class Player
{
    protected:
        unsigned int count_of_guesses = 0;
        int your_number = -1;
        int your_guess = -1;

    public:
        unsigned int getCountOfGuesses();
        int getYourNumber();
        int getYourGuess();

        void addCountOfGuess();
        void setYourGuess(int);
        void setYourNumber(int);
};
