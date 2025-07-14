# 💫 LeetCode Problem 5: Longest Palindromic Substring

## 1. 📄 Problem Explanation

Given a string `s`, return the **longest palindromic substring** in `s`.

A **palindrome** is a string that reads the same forward and backward (e.g., "racecar", "madam").

### 🔹 Example:

---

## 2. ✅ Approach

We use the **expand-around-center** technique to find the longest palindromic substring.

For each character in the string, we treat it as the **center of a potential palindrome** and expand outwards to check for both:
- Odd-length palindromes (center at one character)
- Even-length palindromes (center between two characters)

We compare all results and return the **longest one**.

---

## 3. 🧠 Algorithm

1. Initialize an empty string `result` to store the longest palindrome.
2. Loop through each index `i` in the string:
   - Expand around center `(i, i)` to handle odd-length palindromes.
   - Expand around center `(i, i+1)` to handle even-length palindromes.
   - Keep updating `result` if the current palindrome is longer.
3. The helper function expands the substring from the center while the characters on both sides match.
4. Return the `result` after the loop.

---

## 4. ⏱ Time and Space Complexity

| Complexity | Explanation                               |
|------------|-------------------------------------------|
| ⌛ Time     | **O(N²)** – Expanding around all centers (N characters, each up to N/2 expansion) |
| 🧠 Space    | **O(1)** – No extra space except variables (we’re not using DP arrays) |

---

## 5. 💻 C++ Code (with Comments)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Helper to expand from center and return palindrome substring
    string expandFromCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the valid palindromic substring
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            // Expand around single character (odd length)
            string odd = expandFromCenter(s, i, i);

            // Expand around two characters (even length)
            string even = expandFromCenter(s, i, i + 1);

            // Update result with longer one
            if (odd.length() > result.length()) result = odd;
            if (even.length() > result.length()) result = even;
        }

        return result;
    }
};
