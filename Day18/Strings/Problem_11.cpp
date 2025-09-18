#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordMap;
        vector<vector<int>> res;
        
        // Store words in a map for reverse lookup
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]] = i;
        }
        
        // Helper function to check palindrome
        auto isPalindrome = [](const string &s) -> bool {
            int l = 0, r = s.size() - 1;
            while (l < r) {
                if (s[l++] != s[r--]) return false;
            }
            return true;
        };
        
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (int j = 0; j <= word.size(); j++) {
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);
                
                // Case 1: prefix is palindrome, check reversed suffix
                if (isPalindrome(prefix)) {
                    string revSuffix = suffix;
                    reverse(revSuffix.begin(), revSuffix.end());
                    if (wordMap.count(revSuffix) && wordMap[revSuffix] != i) {
                        res.push_back({wordMap[revSuffix], i});
                    }
                }
                
                // Case 2: suffix is palindrome, check reversed prefix
                if (j != word.size() && isPalindrome(suffix)) {
                    string revPrefix = prefix;
                    reverse(revPrefix.begin(), revPrefix.end());
                    if (wordMap.count(revPrefix) && wordMap[revPrefix] != i) {
                        res.push_back({i, wordMap[revPrefix]});
                    }
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;

    // Input words
    vector<string> words = {"bat", "tab", "cat", "tac", "a"};
    
    // Find palindrome pairs
    vector<vector<int>> ans = sol.palindromePairs(words);
    
    // Print the results
    cout << "Palindrome Pairs:\n";
    for (auto &pair : ans) {
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";
    }
    
    return 0;
}
