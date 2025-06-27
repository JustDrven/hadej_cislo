#include "game.h"
#include "messages.h"

void Game::setYourNumber()
{
    do
    {
        Console::clear();

        if (!isNumber(your_number)) 
        {
            your_number = -1;
            Console::printLine("Input musí být číslo!");
        }

        Console::printLine("Zadej číslo, které chceš hádat:");
        scanf("%d", &your_number);

    } while (!isDefine(your_number));
}

void Game::end()
{
    Console::printLine(ColorBase::RED + "      Prohrál jsi" + ColorBase::RESET);
    Console::printLine("  Tajné číslo bylo: " + to_string(your_number));
}

bool Game::checkEnd()
{
    return your_guess != your_number && count_of_guesses != GSettings::MAX_GUESS;
}

void Game::win()
{
    Console::printLine(ColorBase::GREEN + "        Vyhrál jsi" + ColorBase::RESET);
    Console::printLine("  Číslo jsi uhádl na " + to_string(count_of_guesses) + ". pokus");
}

void Game::start()
{
    setYourNumber();
    
    Console::clear();

    do
    {
        Console::printLine("Máš posledních " + to_str(GSettings::MAX_GUESS - count_of_guesses) + ". pokusů");
        Console::printLine("Zadej tvůj pokus:");

        scanf("%d", &your_guess);
        
        count_of_guesses++;

    } while (checkEnd());
    
    
    sendStatsMessage(this);
}

bool Game::canWin()
{
    return your_guess == your_number;
}