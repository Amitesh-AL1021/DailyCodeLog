#include <iostream>
#include <string>
using namespace std;

// Define the Solution class
class Solution {
public:
    // Main function to remove k digits
    string removeKdigits(string num, int k) {
        string result = ""; // Stack-like string to build the result

        for (char digit : num) {
            // Remove digits from the back while:
            // - We still have digits to remove (k > 0)
            // - The current digit is smaller than the last one in result
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back(); // Remove the last digit
                k--;
            }
            result.push_back(digit); // Add current digit to result
        }

        // If we still need to remove digits, remove from the end
        while (k-- > 0 && !result.empty()) {
            result.pop_back();
        }

        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }

        // Get the final result without leading zeros
        result = result.substr(start);

        // If result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};

int main() {
    Solution sol;
    string num;
    int k;

    // Take input from user
    cout << "Enter number: ";
    cin >> num;
    cout << "Enter k: ";
    cin >> k;

    // Get and print the result
    string smallest = sol.removeKdigits(num, k);
    cout << "Smallest number after removing " << k << " digits: " << smallest << endl;

    return 0;
}
