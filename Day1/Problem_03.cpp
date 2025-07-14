#include <iostream>
#include <string>
using namespace std;

// Problem 5: Longest Palindromic Substring
class Solution {
public:
    string expandFromCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the valid palindrome substring
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            // Odd-length palindrome
            string odd = expandFromCenter(s, i, i);
            if (odd.size() > result.size()) result = odd;

            // Even-length palindrome
            string even = expandFromCenter(s, i, i + 1);
            if (even.size() > result.size()) result = even;
        }

        return result;
    }
};
