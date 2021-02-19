#include "calc.h"
map<string, double> mp;
double ans, tmp;
int num;
void init() { ans = tmp = num = 0; }
void flush() { // purge tmp value to ans
    if (tmp >= 0.0) {
        ans += tmp;
        tmp = 0;
    }
}
bool is_digit(char x) { return x >= '0' && x <= '9'; }
bool is_uppercase(char x) { return x >= 'A' && x <= 'Z'; }
bool is_lowercase(char x) { return x >= 'a' && x <= 'z'; }
