#include "game.h"
#include "messages.h"
#include "settings.h"

#include "../utils/number.h"
#include "../utils/colors.h"
#include "../utils/strings.h"
#include "../utils/console.h"
#include "../stats/stats.h"

Player& Game::getPlayer()
{
    return this->basePlayer;
}

void Game::setYourNumber()
{

    int your_number_input;
    Player& p = getPlayer();

    do
    {
        Console::clear();

        if (!string_util::isNumber(p.getYourNumber())) 
        {
            p.setYourNumber(-1);
            Console::printLine("Input musí být číslo!");
            break;
        }

        Console::printLine("Zadej číslo, které chceš hádat:");

        scanf("%d", &your_number_input);

        p.setYourNumber(your_number_input);

    } while (!string_util::isDefine(your_number_input));
}

void Game::end()
{
    Stats::write(Losses);

    Console::printLine(ColorBase::RED + "          Prohrál jsi" + ColorBase::RESET);
    Console::printLine("    Tajné číslo bylo: " + string_util::toStr(getPlayer().getYourNumber()));
}

bool Game::checkEnd()
{
    return getPlayer().getYourGuess() != getPlayer().getYourNumber() 
            && getPlayer().getCountOfGuesses() != GSettings::MAX_GUESS;
}

void Game::win()
{

    Stats::write(Wins);
    Player& p = getPlayer();

    Console::printLine(ColorBase::GREEN + "        Vyhrál jsi" + ColorBase::RESET);
    Console::printLine("  Číslo jsi uhádl na " + string_util::toStr(p.getCountOfGuesses()) + ". pokus");
    Console::printLine("    Tajné číslo bylo: " + string_util::toStr(p.getYourNumber()));

}

void Game::start(bool _r)
{

    Player& p = getPlayer();

    if (_r)
        p.setYourNumber(getRandom(0, 10));
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
        Console::printLine("Máš posledních " + string_util::toStr(GSettings::MAX_GUESS - p.getCountOfGuesses()) + ". pokusů");
        Console::printLine("Zadej tvůj pokus:");

        int your_guess_input;
        scanf("%d", &your_guess_input);

        p.setYourGuess(your_guess_input);

        if (string_util::isNumber(p.getYourGuess()) 
                && isBigger(p.getYourNumber(), p.getYourGuess()))

            Console::printLine("Číslo je větší, než to " + string_util::toStr(p.getYourGuess()));
        else
            Console::printLine("Číslo je menší, než to " + string_util::toStr(p.getYourGuess()));

        
        p.addCountOfGuess();

    } while (checkEnd());
    
    
    sendStatsMessage(this);
}

void Game::shutdown()
{
    Stats::flush();
}

bool Game::canWin()
{
    Player& p = getPlayer();

    return p.getYourNumber() == p.getYourGuess();
}