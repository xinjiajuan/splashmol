#include "calc.h"
#include <iostream>
double calc_mass(string input) {
    init();
    bool inGroup = false; // in parentheses flag
    input += '*';
    for (int i = 0; i < (input.length() - 1); i++) {
        if (is_uppercase(input[i]) && !inGroup) { // parse normal char
            if (is_digit(input[i + 1]))           // followed by subscripts?
                tmp += mp[input[i]];
            else if (is_lowercase(input[i + 1])) // name has two chars?
                tmp += multi_name_parse(input[i], input[i+1]);
            else {
                ans += mp[input[i]];
                flush();
            }
        } else if (is_digit(input[i])) { // parse subscript number
            for (int j = i; j < input.length() - 1; j++)  // get multiple digits
                if (is_digit(input[j]))
                    num = num * 10 + (input[j] - '0');
                else
                    break;
            ans += (tmp * num);
            tmp = num = 0;
        } else if (input[i] == ')') { // end of parentheses
            inGroup = false;
        } else if (input[i] == '(' ||
                   inGroup) { // entering a pair of parentheses
            if (!inGroup) flush();
            inGroup = true;
            if (is_uppercase(input[i])) { // parse names
                if (is_lowercase(input[i + 1]))
                    tmp += multi_name_parse(input[i], input[i+1]);
                else 
                    tmp += mp[input[i]];
            }
        } else if (input[i] == '-') { // parse water of hydration
            int tmp_loc = i + 1;
            for (int j = i + 1; j < input.length() - 1;
                 j++, tmp_loc++) // get multiple digits
                if (is_digit(input[j]))
                    num = num * 10 + (input[j] - '0');
                else
                    break;
            if (input[tmp_loc] == 'H' && input[tmp_loc + 1] == '2' &&
                input[tmp_loc + 2] == 'O') { // some pre-checks
                ans += ((num)*18);
                i = tmp_loc + 3;
            }
        }
    }
    flush();
    return ans;
}
