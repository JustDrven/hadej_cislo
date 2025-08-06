/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#include "../include/messages.h"

#include "../include/settings.h"
#include "../include/game.h"

#include "../include/utils/colors.h"
#include "../include/utils/console.h"

void messages::SendStats(Game *g)
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
