#include "calc.h"
map<string, double> mp; // single char map
double ans, tmp;
int num;
void init() { ans = tmp = num = 0; }
void init_table_school() {
    mp.clear();
    mp["C"] = 12.0;
    mp["H"] = 1.0;
    mp["O"] = 16.0;
    mp["N"] = 14.0;
    mp["P"] = 31.0;
    mp["S"] = 32.0;
    mp["K"] = 39.0;
    mp["I"] = 127.0;
    mp["Ba"] = 137.0;
    mp["Au"] = 197.0;
    mp["Ca"] = 40.0;
    mp["Cl"] = 35.5;
    mp["Na"] = 23.0;
    mp["Mg"] = 24.0;
    mp["Al"] = 27.0;
    mp["Si"] = 28.0;
    mp["Mn"] = 55.0;
    mp["Fe"] = 56.0;
    mp["Cu"] = 64.0;
    mp["Zn"] = 65.0;
    mp["Ag"] = 108.0;
    mp["Hg"] = 201.0;
}
void init_table_normal() {
    mp.clear();
    mp["B"] = 10.811;
    mp["C"] = 12.0107;
    mp["F"] = 18.998403163;
    mp["H"] = 1.00794;
    mp["I"] = 126.90447;
    mp["K"] = 39.0983;
    mp["N"] = 14.0067;
    mp["O"] = 15.9994;
    mp["P"] = 30.973761998;
    mp["S"] = 32.065;
    mp["U"] = 238.02891;
    mp["V"] = 50.9415;
    mp["W"] = 183.84;
    mp["Y"] = 88.90584;
    mp["Ac"] = 227.0277;
    mp["Ag"] = 107.8682;
    mp["Al"] = 26.9815385;
    mp["Am"] = 243.0614;
    mp["Ar"] = 39.948;
    mp["As"] = 74.921595;
    mp["At"] = 196.966569;
    mp["Ba"] = 137.327;
    mp["Be"] = 9.0121831;
    mp["Bh"] = 274.1436;
    mp["Bi"] = 208.9804;
    mp["Bk"] = 247.0703;
    mp["Br"] = 79.904;
    mp["Ca"] = 40.078;
    mp["Cd"] = 112.414;
}
void flush() { // purge tmp value to ans
    if (tmp >= 0.0) {
        ans += tmp;
        tmp = 0;
    }
}
bool is_digit(char x) { return x >= '0' && x <= '9'; }
bool is_uppercase(char x) { return x >= 'A' && x <= 'Z'; }
bool is_lowercase(char x) { return x >= 'a' && x <= 'z'; }
