class Game
{

    public:
        inline static void win(int count_of_guesses) {
            print_line(ColorBase::GREEN + "     Vyhrál jsi" + ColorBase::RESET);
            print_line("Číslo jsi uhádl na " + to_string(count_of_guesses) + ". pokus");
        }

        inline static void end() {
            print_line(ColorBase::RED + "     Prohrál jsi" + ColorBase::RESET);
        }

};
