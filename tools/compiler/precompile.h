#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "starter.h"

typedef const char* STR;
typedef unsigned int UINT;

#define PRINT(s) printf(s "\n")
#define LOG(s) PRINT("[INFO] " s)
#define ERROR(s) PRINT("[ERROR] " s)

