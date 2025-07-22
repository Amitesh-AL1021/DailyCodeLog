#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are different, they can't be anagrams
        if (s.length() != t.length()) return false;

        // Frequency array for 26 lowercase letters
        vector<int> count(26, 0);

        // Count frequency from both strings
        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++; // increment for s
            count[t[i] - 'a']--; // decrement for t
        }

        // If all counts are zero, then it's an anagram
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0)
                return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    string s = "anagram";
    string t = "nagaram";

    bool result = sol.isAnagram(s, t);

    cout << "String 1: " << s << endl;
    cout << "String 2: " << t << endl;
    cout << "Is Anagram: " << (result ? "True" : "False") << endl;

    return 0;
}
