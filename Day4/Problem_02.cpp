#include <iostream>
#include <vector>
using namespace std;

// ✅ Solution class containing the longestPalindrome function
class Solution {
public:
    int longestPalindrome(string s) {
        // Frequency counters for lowercase and uppercase letters
        vector<int> lower(26, 0); // 'a' to 'z'
        vector<int> upper(26, 0); // 'A' to 'Z'

        // ✅ Step 1: Count frequency of each character in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                // If lowercase, update in lower[]
                lower[s[i] - 'a']++;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                // If uppercase, update in upper[]
                upper[s[i] - 'A']++;
            }
        }

        int count = 0;     // Final length of the longest palindrome
        bool odd = false;  // To track if any odd frequency was found

        // ✅ Step 2: Add all even frequencies and (odd - 1)
        for (int i = 0; i < 26; i++) {
            // Process lowercase
            if (lower[i] % 2 == 0) {
                count += lower[i]; // Add full if even
            } else {
                count += lower[i] - 1; // Add even part only
                odd = true;            // Mark that we found an odd
            }

            // Process uppercase
            if (upper[i] % 2 == 0) {
                count += upper[i]; // Add full if even
            } else {
                count += upper[i] - 1; // Add even part only
                odd = true;            // One odd can go in center
            }
        }

        // ✅ Step 3: Add 1 if any odd frequency was found (center character)
        return count + (odd ? 1 : 0);
    }
};

// ✅ Main function for testing
int main() {
    Solution obj;
    string input;

    // 📥 Take input from user
    cout << "Enter a string: ";
    cin >> input;

    // 🧠 Call the function and get result
    int result = obj.longestPalindrome(input);

    // 📤 Output the result
    cout << "Longest Palindrome Length: " << result << endl;

    return 0;
}
