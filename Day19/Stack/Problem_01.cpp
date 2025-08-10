#include <iostream>   // For input/output
#include <stack>      // For stack data structure
#include <string>     // For using string
using namespace std;

class Solution {
public:
    // Function to check if the given string has valid parentheses/brackets
    bool isValid(string str) {
        stack<char> st;  // Stack to store opening brackets

        // Loop through each character in the string
        for (int i = 0; i < str.size(); i++) {
            // If the character is an opening bracket, push it to the stack
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
            } 
            else { // The character is a closing bracket
                // If the stack is empty, there is no matching opening bracket
                if (st.empty()) {
                    return false;
                }
                // Check if the top of the stack matches the current closing bracket
                if ((st.top() == '(' && str[i] == ')') || 
                    (st.top() == '{' && str[i] == '}') || 
                    (st.top() == '[' && str[i] == ']')) {
                    st.pop(); // Matching pair found → remove the opening bracket from stack
                } 
                else {
                    return false; // Mismatch found
                }
            }
        }
        // If stack is empty, all brackets were matched
        return st.empty();
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a string of brackets: ";
    cin >> s;

    if (obj.isValid(s)) {
        cout << "Valid\n";
    } else {
        cout << "Invalid\n";
    }

    return 0;
}

/*
================= DRY RUN =================

Example 1: 
Input: "{[()]}"
Step-by-step:
1. '{' → opening → push → stack: { 
2. '[' → opening → push → stack: { [ 
3. '(' → opening → push → stack: { [ ( 
4. ')' → matches '(' → pop → stack: { [
5. ']' → matches '[' → pop → stack: { 
6. '}' → matches '{' → pop → stack: (empty)
Result: Stack empty → VALID

Example 2:
Input: "{[(])}"
Step-by-step:
1. '{' → opening → push → stack: {
2. '[' → opening → push → stack: { [
3. '(' → opening → push → stack: { [ (
4. ']' → top is '(' but got ']' → mismatch → return false
Result: INVALID
*/
