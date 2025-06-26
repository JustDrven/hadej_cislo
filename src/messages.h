#include "settings.h"
#include "game.h"
#include "../utils/colors.h"
#include "../utils/console.h"
#include "../utils/strings.h"

void send_stats_message(int your_number, int your_guess, int count_of_guesses) {
    Console::clear_console();

    Game g(count_of_guesses);

    Console::print_line();
    Console::print_line(GSettings::LINE);
    Console::print_line();
    Console::print_line();

    if (your_number == your_guess)
        g.Win();
    else
        g.End();
    

    Console::print_line();
    Console::print_line();
    Console::print_line(GSettings::LINE);
    Console::print_line();
    
}
