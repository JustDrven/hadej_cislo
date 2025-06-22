#include "../utils/console.h"
#include "../utils/logger.h"
#include "../utils/strings.h"
#include "../game/settings.h"
#include "../utils/colors.h"

using namespace std;

void send_stats_message(int your_number, int your_guess, int count_of_guesses) {
    clear_console();

    log("");
    log(GSettings::LINE);
    log("");
    log("");

    if (your_number == your_guess)
    {
        log(ColorBase::GREEN + "     Vyhrál jsi" + ColorBase::RESET);
        log("Číslo jsi uhádl na " + to_string(count_of_guesses) + ". pokus");
    }
    else
    {
        log(ColorBase::RED + "     Prohrál jsi" + ColorBase::RESET);
    }

    log("");
    log("");
    log(GSettings::LINE);
    log("");
    
}
