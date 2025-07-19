#include<iostream>
#include<unordered_map>
using namespace std;

bool areAnagrams(string s1, string s2) {
    // Step 1: Length check
    if (s1.length() != s2.length())
        return false;

    // Step 2: Frequency map of s1
    unordered_map<char, int> freq;

    for (char ch : s1) {
        freq[ch]++;
    }

    // Step 3: Subtract frequency using s2
    for (char ch : s2) {
        freq[ch]--;
        if (freq[ch] < 0)
            return false;
    }

    // All counts should be zero
    return true;
}

int main() {
    string s1 = "listen";
    string s2 = "silent";

    if (areAnagrams(s1, s2))
        cout << "Yes, they are anagrams.";
    else
        cout << "No, they are not anagrams.";

    return 0;
}
