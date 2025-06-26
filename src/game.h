#ifndef GAME_H
#define GAME_H

class Game
{

    public:
        int count_of_guesses = 0;
        int your_number = -1;
        int your_guess = -1;

    public:
        void start();
        void win();
        void end();

        bool canWin();
        bool canStop();

        void setYourNumber();

};

#endif