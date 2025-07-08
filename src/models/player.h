#ifndef PLAYER_H
#define PLAYER_H

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
        void setYourGuess(int _yg);
        void setYourNumber(int _yn);
};

#endif