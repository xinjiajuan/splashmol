#include "calc.h"
map<char, double> mp;    // single char map
map<string, double> mp2; // double char map
double ans, tmp;
int num;
void init() { ans = tmp = num = 0; }
void init_table() {
    mp['C'] = 12.0;
    mp['H'] = 1.0;
    mp['O'] = 16.0;
    mp['N'] = 14.0;
    mp['P'] = 31.0;
    mp['S'] = 32.0;
    mp['K'] = 39.0;
    mp['I'] = 127.0;
    mp2["Ba"] = 137.0;
    mp2["Au"] = 197.0;
    mp2["Ca"] = 40.0;
    mp2["Cl"] = 35.5;
    mp2["Na"] = 23.0;
    mp2["Mg"] = 24.0;
    mp2["Al"] = 27.0;
    mp2["Si"] = 28.0;
    mp2["Mn"] = 55.0;
    mp2["Fe"] = 56.0;
    mp2["Cu"] = 64.0;
    mp2["Zn"] = 65.0;
    mp2["Ag"] = 108.0;
    mp2["Hg"] = 201.0;
}
void flush() { // purge tmp value to ans
    if (tmp >= 0.0) {
        ans += tmp;
        tmp = 0;
    }
}
double multi_name_parse(char a, char b) { // parse names with two chars
    string tmpstr;
    tmpstr += a;
    tmpstr += b;
    return mp2[tmpstr];
}
