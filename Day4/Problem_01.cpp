#include <iostream>
#include <vector>
using namespace std;

// ✅ Class to handle palindrome partitioning logic
class Solution {
public:
    vector<vector<string>> result;  // Stores all valid palindrome partitions

    // ✅ Function to check if a substring is a palindrome
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;  // If any mismatch, not a palindrome
            start++;
            end--;
        }
        return true;  // It’s a palindrome
    }

    // ✅ Backtracking function to explore all partitions
    void backtrack(string &s, int index, vector<string> &path) {
        // Base case: if index reaches the end of the string
        if (index == s.size()) {
            result.push_back(path);  // Add current path to result
            return;
        }

        // Try every possible substring starting from index
        for (int i = index; i < s.size(); i++) {
            // Check if s[index...i] is a palindrome
            if (isPalindrome(s, index, i)) {
                // ✅ Include the current palindrome substring in path
                path.push_back(s.substr(index, i - index + 1));

                // 🔁 Recurse for the rest of the string
                backtrack(s, i + 1, path);

                // ❌ Backtrack: remove last added substring
                path.pop_back();
            }
        }
    }

    // ✅ Main function to be called in main()
    vector<vector<string>> partition(string s) {
        vector<string> path;         // Current partition path
        backtrack(s, 0, path);       // Start recursion from index 0
        return result;               // Return all valid partitions
    }
};

// ✅ Driver code to run and test in VS Code
int main() {
    Solution obj;

    // 📥 User input
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // 🧠 Get all palindromic partitions
    vector<vector<string>> ans = obj.partition(s);

    // 📤 Display the result
    cout << "\nAll Palindromic Partitions:\n";
    for (const auto &vec : ans) {
        cout << "[ ";
        for (const auto &str : vec) {
            cout << "\"" << str << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}
