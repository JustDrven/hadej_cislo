#include <string>
#include <cctype>

using namespace std;

string to_str(int value) 
{
    return to_string(value);
}

bool isNumber(int _ci) {
    return isdigit(_ci) == 0;
}

bool isDefine(int _ci) {
    return _ci != -1;
}