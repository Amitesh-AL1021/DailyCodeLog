#include <iostream>   // For input/output (cout, cin)
#include <vector>     // For using the vector container
#include <string>     // For string operations
using namespace std;

// Define the class Solution with the required function
class Solution {
public:
    // This function takes an arithmetic expression as a string
    // and returns all possible results from computing different
    // valid ways to add parentheses.
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result; // To store all computed results

        // Loop through the expression to look for operators
        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            // Check if the current character is an operator
            if (c == '+' || c == '-' || c == '*') {
                // Split the expression into left and right parts
                // based on the position of the operator
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                // Recursively compute all results from left and right parts
                vector<int> leftResults = diffWaysToCompute(left);
                vector<int> rightResults = diffWaysToCompute(right);

                // Combine results from both sides using the current operator
                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (c == '+')
                            result.push_back(l + r);   // Add result
                        else if (c == '-')
                            result.push_back(l - r);   // Subtract result
                        else if (c == '*')
                            result.push_back(l * r);   // Multiply result
                    }
                }
            }
        }

        // If no operator found, the entire expression is a number
        // Convert it from string to integer and return as single result
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result; // Return all possible computation results
    }
};
