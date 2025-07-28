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

    if (g->CanWin())
        g->Win();
    else
        g->End();


    g->Shutdown();
    

    Console::printLine();
    Console::printLine();
    Console::printLine(GSettings::LINE);
    Console::printLine();
}
