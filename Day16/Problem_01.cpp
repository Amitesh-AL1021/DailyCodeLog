#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Map to store the last index of each character
        unordered_map<char, int> charIndex;

        // Initialize the start of the current window and max length
        int left = 0;
        int maxLength = 0;

        // Loop through the string with right as the end of the window
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

            // If current character is found in map and is inside the current window
            if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left) {
                // Move the left side of the window to right of last seen index
                left = charIndex[currentChar] + 1;
            }

            // Update or insert the current character's latest index
            charIndex[currentChar] = right;

            // Update the maxLength if the current window is larger
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;  // Output: 3
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;     // Output: 1
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;    // Output: 3
    cout << sol.lengthOfLongestSubstring("") << endl;          // Output: 0

    return 0;
}
