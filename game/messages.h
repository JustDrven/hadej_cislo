#include "../utils/console.h"
#include "../utils/logger.h"
#include "../utils/strings.h"

using namespace std;

static string LINE = "=================================";

void send_stats_message(int your_number, int your_guess, int count_of_guesses) {
    clear_console();

    log(LINE);
    log("");
    log("");

    if (your_number == your_guess)
    {
        log("     Vyhrál jsi");
        log("Číslo jsi uhádl na " + to_string(count_of_guesses) + ". pokus");
    }
    else
    {
        log("     Prohrál jsi");
    }

    log("");
    log("");
    log(LINE);
    
}
