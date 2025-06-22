#include "../utils/console.h"
#include "../utils/strings.h"
#include "../game/settings.h"
#include "../utils/colors.h"
#include "game.h"

using namespace std;

void send_stats_message(int your_number, int your_guess, int count_of_guesses) {
    clear_console();

    print_line();
    print_line(GSettings::LINE);
    print_line();
    print_line();

    if (your_number == your_guess)
        Game::win(count_of_guesses);
    else
        Game::end();
    

    print_line();
    print_line();
    print_line(GSettings::LINE);
    print_line();
    
}
