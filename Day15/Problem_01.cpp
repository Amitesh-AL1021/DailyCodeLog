#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Palindrome Partitioning II (LeetCode 132)
    ---------------------------------------------------
    Given a string s, partition it into substrings such that every substring
    is a palindrome. Return the minimum number of cuts needed.

    Example:
    Input: "aab"
    Output: 1  -> because "aa | b" is the optimal cut

    Approach:
    ----------
    1. First, precompute all substrings that are palindromes using DP.
    2. Then, use another DP array to find the minimum cuts.
*/

// Function to calculate minimum cuts
int minCut(string s) {
    int n = s.length();

    // Step 1: Precompute palindrome substrings using a 2D DP table
    // isPalindrome[i][j] = true if substring s[i..j] is palindrome
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    for (int end = 0; end < n; ++end) {
        for (int start = 0; start <= end; ++start) {
            // Check if characters match and the inside substring is palindrome
            // end - start <= 2 handles single char and two-char substrings
            if (s[start] == s[end] && (end - start <= 2 || isPalindrome[start + 1][end - 1])) {
                isPalindrome[start][end] = true;
            }
        }
    }

    // Step 2: Use a DP array to calculate the minimum cuts
    // dp[i] = minimum cuts needed for substring s[0..i]
    vector<int> dp(n, 0);

    for (int i = 0; i < n; ++i) {
        // If s[0..i] is already a palindrome, no cut needed
        if (isPalindrome[0][i]) {
            dp[i] = 0;
        } else {
            // Initialize with max cuts (i cuts = every char separate)
            dp[i] = i;
            // Try making a cut at every possible position j < i
            for (int j = 0; j < i; ++j) {
                if (isPalindrome[j + 1][i]) {
                    // If s[j+1..i] is palindrome, we can make a cut after j
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }

    return dp[n - 1];  // Answer is min cuts for full string s[0..n-1]
}

int main() {
    // Fast I/O (optional for competitive programming)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input from user
    cout << "Enter a string: ";
    string s;
    cin >> s;

    // Calculate and print result
    int result = minCut(s);
    cout << "Minimum cuts needed for palindrome partitioning: " << result << endl;

    /*
        Example run:
        Input: aab
        Output: 1 (because "aa | b")
    */

    return 0;
}
