/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#pragma once

#include "../../dev/os.h"

typedef int BOOL;

#define FALSE 0
#define TRUE 1

#ifdef __START
#define __CAN_START TRUE
#else
#define __CAN_START FALSE
#endif