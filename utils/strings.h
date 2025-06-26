#include <string>
#include <cctype>

using namespace std;

string to_str(int value) 
{
    return to_string(value);
}

bool isNumber(int& _ci) {
    int _cv = isdigit(_ci);

    return _cv == 1;
}

bool isDefine(int& _ci) {
    return _ci != -1;
}