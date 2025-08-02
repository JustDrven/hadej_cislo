#pragma once

#include <fstream>
#include <vector>

typedef std::string STR_T;
typedef std::ifstream ISTREAM_T;
typedef std::ofstream OSTREAM_T;
typedef std::vector<STR_T> STRVEC_T;
typedef unsigned int UINT;

#define ISTATIC inline static
#define STATIC static
#define LINES(f, l) std::getline(f, l)


