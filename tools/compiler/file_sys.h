/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#pragma once

#include "precompile.h"

#ifdef __WIN64
#define __SUFFIX "exe"
#elif __WIN36
#define __SUFFIX "exe"
#elif __APPLE__
#define __SUFFIX "o"
#elif __LINUX__
#define __SUFFIX "o"
#else
#define __SUFFIX "out"
#endif
