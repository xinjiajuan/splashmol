#ifndef CALC_H
#define CALC_H
#include <iostream>
#include <map>
#include <string>
using namespace std;
void init();
void init_table();
void flush();
double multi_name_parse(char a, char b);
double calc_mass(string input);
extern map<char, double> mp;    // single char map
extern map<string, double> mp2; // double char map
extern double ans, tmp;
extern int num;
#endif // CALC_H
