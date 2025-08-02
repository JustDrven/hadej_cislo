#include "messages.h"

#include "settings.h"
#include "game.h"

#include "../utils/colors.h"
#include "../utils/console.h"

void messages::SendStats(Game* g)
{
    Console::Clear();

    Console::PrintLine();
    Console::PrintLine(GSettings::LINE);
    Console::PrintLine();
    Console::PrintLine();

    if (g->CanWin())
        g->Win();
    else
        g->End();


    g->Shutdown();
    

    Console::PrintLine();
    Console::PrintLine();
    Console::PrintLine(GSettings::LINE);
    Console::PrintLine();
}
