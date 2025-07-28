#pragma once

class Player
{
    protected:
        unsigned int count_of_guesses = 0;
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
