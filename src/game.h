#ifndef GAME_H
#define GAME_H

class Game
{

    private:
        int count_of_guesses;

    public:
        Game(int& count_of_guesses);
        void Win();
        void End();
};


#endif