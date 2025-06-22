#include "game/messages.h"

static int MAX_GUESS = 5;

int main()
{
    clear_console();

    int your_number;

    log("Zadej číslo, které chceš hádat:");
    scanf("%d", &your_number);
    
    clear_console();



    int your_guess;
    int count_of_guesses = 0;

    do
    {
        log("Máš posledních " + to_str(count_of_guesses) + ". pokusů");
        log("Zadej tvůj pokus:");

        count_of_guesses++;


        scanf("%d", &your_guess);
    } while (your_guess != your_number && count_of_guesses != MAX_GUESS);
    
    
    send_stats_message(your_number, your_guess, count_of_guesses);

    return 0;
}
