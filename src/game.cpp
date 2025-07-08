#include "game.h"
#include "messages.h"
#include "settings.h"

#include "../utils/number.h"
#include "../utils/colors.h"
#include "../utils/strings.h"
#include "../utils/console.h"
#include "../stats/stats.h"

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
            break;
        }

        Console::printLine("Zadej číslo, které chceš hádat:");

        scanf("%d", &your_number_input);

        basePlayer.setYourNumber(your_number_input);

    } while (!isDefine(your_number_input));
}

void Game::end()
{

    Stats::write(Losses);

    Console::printLine(ColorBase::RED + "          Prohrál jsi" + ColorBase::RESET);
    Console::printLine("    Tajné číslo bylo: " + toStr(basePlayer.getYourNumber()));
}

bool Game::checkEnd()
{
    return basePlayer.getYourGuess() != basePlayer.getYourNumber() 
            && basePlayer.getCountOfGuesses() != GSettings::MAX_GUESS;
}

void Game::win()
{

    Stats::write(Wins);

    Console::printLine(ColorBase::GREEN + "        Vyhrál jsi" + ColorBase::RESET);
    Console::printLine("  Číslo jsi uhádl na " + toStr(basePlayer.getCountOfGuesses()) + ". pokus");
    Console::printLine("    Tajné číslo bylo: " + toStr(basePlayer.getYourNumber()));

}

void Game::start(bool _r)
{
    if (_r)
        basePlayer.setYourNumber(getRandom(0, 10));
    else
        setYourNumber();
    
    
    
    Console::clear();

    if (_r)
    {
        Console::printLine(GSettings::LINE);
        Console::printLine();
        Console::printLine("Čislo bylo náhodně vybrané od 0 - 10");
        Console::printLine();
    }

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

void Game::shutdown()
{
    Stats::flush();
}

bool Game::canWin()
{
    return basePlayer.getYourNumber() == basePlayer.getYourGuess();
}