#include "calc.h"
#include <iostream>
double calc_mass(string input) {
    init();
    bool inGroup = false; // in parentheses flag
    input += '*';
    unsigned long len = input.length();
    for (unsigned long i = 0; i < (len - 1); i++) {
        char i1 = input.at(i), i2 = input.at(i + 1);
        if (is_uppercase(i1) && !inGroup) { // parse normal char
            if (is_digit(i2))               // followed by subscripts?
                tmp += mp[i1];
            else if (is_lowercase(i2)) // name has two chars?
                tmp += multi_name_parse(i1, i2);
            else {
                ans += mp[i1];
                flush();
            }
        } else if (is_digit(i1)) { // parse subscript number
            for (unsigned long j = i; j < (len - 1);
                 j++) { // get multiple digits
                char i3 = input.at(j);
                if (is_digit(i3))
                    num = num * 10 + (i3 - '0');
                else
                    break;
            }
            ans += (tmp * num);
            tmp = num = 0;
        } else if (i1 == ')') { // end of parentheses
            inGroup = false;
        } else if (i1 == '(' || inGroup) { // entering a pair of parentheses
            if (!inGroup) flush();
            inGroup = true;
            if (is_uppercase(i1)) { // parse names
                if (is_lowercase(i2))
                    tmp += multi_name_parse(i1, i2);
                else
                    tmp += mp[i1];
            }
        } else if (i1 == '-') { // parse water of hydration
            unsigned long tmp_loc = i + 1;
            for (unsigned long j = i + 1; j < (len - 1);
                 j++, tmp_loc++) { // get multiple digits
                char i3 = input.at(j);
                if (is_digit(i3))
                    num = num * 10 + (i3 - '0');
                else
                    break;
            }
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
