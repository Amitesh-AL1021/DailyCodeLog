#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        long result = 0;     // Current evaluated result
        long number = 0;     // Current number being formed
        int sign = 1;        // Current sign (+1 or -1)
        stack<int> stk;      // Stack to store previous result and sign

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                // Build the number (could be multi-digit)
                number = number * 10 + (ch - '0');
            } 
            else if (ch == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } 
            else if (ch == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } 
            else if (ch == '(') {
                // Save the current state
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } 
            else if (ch == ')') {
                result += sign * number;
                number = 0;
                result *= stk.top(); // Restore sign
                stk.pop();
                result += stk.top(); // Restore previous result
                stk.pop();
            }
            // Ignore spaces
        }

        // Add any last pending number
        if (number != 0) {
            result += sign * number;
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> expressions = {
        "1 + 1", 
        " 2-1 + 2 ", 
        "(1+(4+5+2)-3)+(6+8)",
        "2147483647",  
        "(5-(1+2))+4"  
    };

    for (auto &expr : expressions) {
        cout << "Expression: " << expr << "\n";
        cout << "Result: " << sol.calculate(expr) << "\n";
        cout << "----------------------\n";
    }

    return 0;
}

/*
================ DRY RUN for (1+(4+5+2)-3)+(6+8) =================

Initial: result=0, sign=1, number=0, stack=[]

'(' -> push result=0, sign=1 -> stack=[0,1], reset result=0, sign=1
'1' -> number=1
'+' -> result=0 + (1*1)=1, number=0, sign=1
'(' -> push result=1, sign=1 -> stack=[0,1,1,1], reset result=0
'4' -> number=4
'+' -> result=4, number=0, sign=1
'5' -> number=5
'+' -> result=9, number=0, sign=1
'2' -> number=2
')' -> result=9+(1*2)=11, multiply by last sign=1 -> result=11
       add last result=1 -> result=12, stack=[0,1]
'-' -> result=12, number=0, sign=-1
'3' -> number=3
')' -> result=12 + (-1*3)=9, multiply by last sign=1 -> result=9
       add last result=0 -> result=9, stack=[]
'+' -> result=9, number=0, sign=1
'(' -> push result=9, sign=1 -> stack=[9,1], reset result=0
'6' -> number=6
'+' -> result=6, number=0, sign=1
'8' -> number=8
')' -> result=6+(1*8)=14, multiply by last sign=1 -> result=14
       add last result=9 -> result=23, stack=[]

END: number=0 -> Final result=23

==================================================================
*/
