#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) 
        return false;

    int freq[26] = {0};  // Only for lowercase English letters

    for (char c : s) 
        freq[c - 'a']++;   

    for (char c : t) {
        freq[c - 'a']--;   
        if (freq[c - 'a'] < 0) 
            return false; 
    }

    return true;
}

int main() {
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t))
        cout << "✅ They are anagrams!" << endl;
    else
        cout << "❌ They are not anagrams!" << endl;

    return 0;
}
