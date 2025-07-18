#include "messages.h"

#include "settings.h"
#include "game.h"

#include "../utils/colors.h"
#include "../utils/console.h"

void messages::sendStats(Game* g)
{
    Console::clear();

    Console::printLine();
    Console::printLine(GSettings::LINE);
    Console::printLine();
    Console::printLine();

    if (g->canWin())
        g->win();
    else
        g->end();


    g->shutdown();
    

    Console::printLine();
    Console::printLine();
    Console::printLine(GSettings::LINE);
    Console::printLine();
}
