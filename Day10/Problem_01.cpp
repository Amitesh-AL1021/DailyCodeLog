#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// LeetCode 187: Repeated DNA Sequences
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;       // Set to store unique 10-letter sequences
        unordered_set<string> repeated;   // Set to store sequences seen more than once
        vector<string> result;            // Final result vector

        // Edge case: if the string is shorter than 10, return empty result
        if (s.length() < 10) return result;

        // Slide a window of length 10 across the string
        for (int i = 0; i <= s.length() - 10; i++) {
            string sequence = s.substr(i, 10); // extract 10-letter substring
            if (seen.count(sequence)) {
                // If sequence already seen before, add to repeated set
                repeated.insert(sequence);
            } else {
                // Otherwise, mark it as seen
                seen.insert(sequence);
            }
        }

        // Copy all repeated sequences into result vector
        for (const string& seq : repeated) {
            result.push_back(seq);
        }

        return result;
    }
};

int main() {
    Solution sol;
    string dna = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    vector<string> repeatedSequences = sol.findRepeatedDnaSequences(dna);

    cout << "Repeated 10-letter DNA sequences are:" << endl;
    for (string seq : repeatedSequences) {
        cout << seq << endl;
    }

    return 0;
}
