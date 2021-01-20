#include "calc.h"
double calc_mass(string input) {
    init();
    bool inGroup = false; // in parentheses flag
    input += '*';
    for (int i = 0; i < (input.length() - 1); i++) {
        if ((input[i] >= 'A' && input[i] <= 'Z') && !inGroup) { // parse normal char
            if (input[i + 1] >= '0' && input[i + 1] <= '9') // followed by subscripts?
                tmp += mp[input[i]];
            else if (input[i + 1] >= 'a' && input[i + 1] <= 'z') // name has two chars?
                tmp += multi_name_parse(input[i], input[i+1]);
            else {
                ans += mp[input[i]];
                flush();
            }
        } else if (input[i] >= '0' && input[i] <= '9') {  // parse subscript number
            for (int j = i; j < input.length() - 1; j++)  // get multiple digits
                if (input[j] >= '0' && input[j] <= '9') 
                    num = num * 10 + (input[j] - '0');
                else
                    break;
            ans += (tmp * num);
            tmp = num = 0;
        } else if (input[i] == ')') { // end of parentheses
            inGroup = false;
        } else if (input[i] == '(' || inGroup) { // entering a pair of parentheses
            if (!inGroup) flush();
            inGroup = true;
            if (input[i] >= 'A' && input[i] <= 'Z') { // parse names
                if (input[i + 1] >= 'a' && input[i + 1] <= 'z')
                    tmp += multi_name_parse(input[i], input[i+1]);
                else 
                    tmp += mp[input[i]];
            }
        }
    }
    flush();
    return ans;
}
