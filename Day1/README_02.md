# 🔠 LeetCode Problem 3: Longest Substring Without Repeating Characters

## 1. 📄 Problem Explanation

Given a string `s`, find the length of the **longest substring** that contains **no repeating characters**.

A **substring** is a contiguous sequence of characters within a string.

### 🔹 Example:

---

## 2. ✅ Approach

We use the **sliding window technique** with a **hash set** to track characters that are already in the current window (substring).

- Start with two pointers: `left` and `right`.
- Move the `right` pointer forward and add characters to the set.
- If a duplicate is found, move the `left` pointer to shrink the window until the duplicate is removed.
- Track the maximum length of valid substrings during the process.

---

## 3. 🧠 Algorithm

1. Create a hash set `seen` to keep track of unique characters in the current window.
2. Initialize two pointers: `left = 0`, `right = 0`, and `maxLen = 0`.
3. Iterate through the string with the `right` pointer:
   - If `s[right]` is **not** in `seen`, add it and update `maxLen`.
   - If it's already in `seen`, remove `s[left]` and increment `left` until `s[right]` is no longer in `seen`.
4. Repeat until the end of the string.
5. Return `maxLen`.

---

## 4. ⏱ Time and Space Complexity

| Complexity | Explanation                              |
|------------|------------------------------------------|
| ⌛ Time     | **O(N)** – Each character is visited at most twice (once by `right`, once by `left`) |
| 🧠 Space    | **O(min(N, M))** – At most `M` characters stored in set, where `M` is the size of character set (like 26 for lowercase, 128 for ASCII) |

---

## 5. 💻 C++ Code (with Comments)

```cpp
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0, maxLen = 0;

        // Right pointer moves forward
        for (int right = 0; right < s.size(); right++) {
            // If character is already seen, shrink the window from the left
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            // Add current character and update max length
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
