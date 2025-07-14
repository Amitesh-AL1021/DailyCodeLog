# LeetCode Problem 10: Regular Expression Matching

## 📄 Problem Statement

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:

- `'.'` Matches any single character.  
- `'*'` Matches zero or more of the preceding element.

The matching should **cover the entire input string** (not partial match).

---

## 🧪 Examples


---

## ✅ Constraints

- `1 <= s.length <= 20`
- `1 <= p.length <= 30`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `.` and `*`.

---

## 💡 Approach

We use **Dynamic Programming** to check whether the string `s` matches the pattern `p`.  
We define `dp[i][j]` as `true` if `s[0...i-1]` matches `p[0...j-1]`, otherwise `false`.

### How '*' is handled:
- `'*'` matches **zero** of the previous character → `dp[i][j] = dp[i][j-2]`
- `'*'` matches **one or more** → `dp[i][j] = dp[i-1][j]` if the character before `'*'` matches

---

## 🧮 Algorithm Steps

1. Initialize a 2D DP table of size `(m+1) x (n+1)` with `false`
2. Set `dp[0][0] = true` for empty string and pattern
3. Fill first row to handle patterns like `"a*"` or `"a*b*c*"`
4. Iterate through `s` and `p`, updating `dp[i][j]` based on:
   - Direct match or `'.'`
   - If `'*'` is found, use the rules above
5. Return `dp[m][n]` (whether full strings match)

---

## 🔍 Code (C++)

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s = "aab";
    string p = "c*a*b";
    cout << boolalpha << isMatch(s, p) << endl;  // Output: true
    return 0;
}
