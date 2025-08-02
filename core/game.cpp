/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#include "../include/game.h"
#include "../include/messages.h"
#include "../include/settings.h"

#include "../include/utils/number.h"
#include "../include/utils/colors.h"
#include "../include/utils/strings.h"
#include "../include/utils/console.h"
#include "../include/stats/stats.h"

Player& Game::GetPlayer()
{
    return this->base_player;
}

void Game::SetYourNumber()
{

    int your_number_input;
    Player& p = GetPlayer();

    do
    {
        Console::Clear();

        if (!string_util::IsNumber(p.GetYourNumber())) 
        {
            p.SetYourNumber(-1);
            Console::PrintLine("Input musí být číslo!");
            break;
        }

        Console::PrintLine("Zadej číslo, které chceš hádat:");

        scanf("%d", &your_number_input);

        p.SetYourNumber(your_number_input);

    } while (!string_util::IsDefine(your_number_input));
}

void Game::End()
{
    Stats::Write(Losses);

    Console::PrintLine(ColorBase::RED + "          Prohrál jsi" + ColorBase::RESET);
    Console::PrintLine("    Tajné číslo bylo: " + string_util::ToStr(GetPlayer().GetYourNumber()));
}

bool Game::CheckEnd()
{
    return GetPlayer().GetYourGuess() != GetPlayer().GetYourNumber() 
            && GetPlayer().GetCountOfGuesses() != GSettings::MAX_GUESS;
}

void Game::Win()
{

    Stats::Write(Wins);
    Player& p = GetPlayer();

    Console::PrintLine(ColorBase::GREEN + "        Vyhrál jsi" + ColorBase::RESET);
    Console::PrintLine("  Číslo jsi uhádl na " + string_util::ToStr(p.GetCountOfGuesses()) + ". pokus");
    Console::PrintLine("    Tajné číslo bylo: " + string_util::ToStr(p.GetYourNumber()));

}

void Game::Start(bool _r)
{

    Player& p = GetPlayer();

    if (_r)
        p.SetYourNumber(number_util::GetRandom(0, 10));
    else
        SetYourNumber();
        
    Console::Clear();

    if (_r)
    {
        Console::PrintLine(GSettings::LINE);
        Console::PrintLine();
        Console::PrintLine("Čislo bylo náhodně vybrané od 0 - 10");
        Console::PrintLine();
    }

    do
    {
        Console::PrintLine("Máš posledních " + string_util::ToStr(GSettings::MAX_GUESS - p.GetCountOfGuesses()) + ". pokusů");
        Console::PrintLine("Zadej tvůj pokus:");

        int your_guess_input;
        scanf("%d", &your_guess_input);

        p.SetYourGuess(your_guess_input);

        if (string_util::IsNumber(p.GetYourGuess()) 
                && number_util::IsBigger(p.GetYourNumber(), p.GetYourGuess()))

            Console::PrintLine("Číslo je větší, než to " + string_util::ToStr(p.GetYourGuess()));
        else
            Console::PrintLine("Číslo je menší, než to " + string_util::ToStr(p.GetYourGuess()));

        
        p.AddCountOfGuess();

    } while (CheckEnd());
    
    
    messages::SendStats(this);
}

void Game::Shutdown()
{
    Stats::Flush();
}

bool Game::CanWin()
{
    Player& p = GetPlayer();

    return p.GetYourNumber() == p.GetYourGuess();
}