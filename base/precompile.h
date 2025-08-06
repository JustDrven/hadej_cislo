/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#pragma once

#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <cctype>

typedef std::string STR_T;
typedef std::ifstream ISTREAM_T;
typedef std::ofstream OSTREAM_T;
typedef std::vector<STR_T> STRVEC_T;
typedef unsigned int UINT;

#define ISTATIC inline static
#define STATIC static
#define LINES(f, l) std::getline(f, l)

#define NL std::endl;
