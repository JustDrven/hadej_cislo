#include "game.h"
#include "messages.h"
#include "../utils/number.h"

void Game::setYourNumber()
{

    int your_number_input;

    do
    {
        Console::clear();

        if (!isNumber(basePlayer.getYourNumber())) 
        {
            basePlayer.setYourNumber(-1);
            Console::printLine("Input musí být číslo!");
        }

        Console::printLine("Zadej číslo, které chceš hádat:");

        scanf("%d", &your_number_input);

        basePlayer.setYourNumber(your_number_input);

    } while (!isDefine(your_number_input));
}

void Game::end()
{
    Console::printLine(ColorBase::RED + "      Prohrál jsi" + ColorBase::RESET);
    Console::printLine("  Tajné číslo bylo: " + toStr(basePlayer.getYourNumber()));
}

bool Game::checkEnd()
{
    return basePlayer.getYourGuess() != basePlayer.getYourNumber() 
            && basePlayer.getCountOfGuesses() != GSettings::MAX_GUESS;
}

void Game::win()
{
    Console::printLine(ColorBase::GREEN + "        Vyhrál jsi" + ColorBase::RESET);
    Console::printLine("  Číslo jsi uhádl na " + to_string(basePlayer.getCountOfGuesses()) + ". pokus");
    Console::printLine("    Tajné číslo bylo: " + toStr(basePlayer.getYourNumber()));

}

void Game::start()
{
    setYourNumber();
    
    Console::clear();

    do
    {
        Console::printLine("Máš posledních " + toStr(GSettings::MAX_GUESS - basePlayer.getCountOfGuesses()) + ". pokusů");
        Console::printLine("Zadej tvůj pokus:");

        int your_guess_input;
        scanf("%d", &your_guess_input);

        basePlayer.setYourGuess(your_guess_input);

        if (isNumber(basePlayer.getYourGuess()) 
                && isBigger(basePlayer.getYourNumber(), basePlayer.getYourGuess()))

            Console::printLine("Číslo je větší, než to " + toStr(basePlayer.getYourGuess()));
        else
            Console::printLine("Číslo je menší, než to " + toStr(basePlayer.getYourGuess()));

        
        basePlayer.addCountOfGuess();

    } while (checkEnd());
    
    
    sendStatsMessage(this);
}

bool Game::canWin()
{
    return basePlayer.getYourNumber() == basePlayer.getYourGuess();
}