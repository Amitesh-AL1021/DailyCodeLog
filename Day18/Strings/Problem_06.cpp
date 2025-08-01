#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for max()
using namespace std;

// Leetcode class structure
class Solution {
public:
    // Function to find the length of the longest substring without repeating characters
    int lengthOfLongestSubstring(string s) {
        // Boolean vector to store if a character is present in the current window
        vector<bool> count(256, false); // 256 for all ASCII characters

        int first = 0;  // Left pointer of sliding window
        int second = 0; // Right pointer of sliding window
        int len = 0;    // To store the maximum length

        // Iterate until the end of the string
        while (second < s.size()) {
            // If the character at 'second' is already in the current window
            while (count[s[second]]) {
                // Remove the character at 'first' from the window and move 'first' forward
                count[s[first]] = false;
                first++;
            }

            // Mark the current character as present
            count[s[second]] = true;

            // Update the maximum length
            len = max(len, second - first + 1);

            // Move 'second' forward
            second++;
        }

        return len;
    }
};

// Main function to run the code
int main() {
    Solution sol;

    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = sol.lengthOfLongestSubstring(input);
    cout << "Length of Longest Substring Without Repeating Characters: " << result << endl;

    return 0;
}
