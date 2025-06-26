#include "src/messages.h"

int main()
{
    Console::clear_console();

    int your_number;

    Console::print_line("Zadej číslo, které chceš hádat:");
    scanf("%d", &your_number);
    
    Console::clear_console();


    int your_guess;
    int count_of_guesses = 0;

    do
    {
        Console::print_line("Máš posledních " + to_str(GSettings::MAX_GUESS - count_of_guesses) + ". pokusů");
        Console::print_line("Zadej tvůj pokus:");

        count_of_guesses++;


        scanf("%d", &your_guess);
    } while (your_guess != your_number && count_of_guesses != GSettings::MAX_GUESS);
    
    
    send_stats_message(your_number, your_guess, count_of_guesses);

    return 0;
}