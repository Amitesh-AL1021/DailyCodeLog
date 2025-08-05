#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0); // Har word ka bitmask yahan store karenge
        vector<int> len(n, 0);  // Har word ki length store karenge

        // Step 1: Bitmask banate hain har word ke liye
        for (int i = 0; i < n; i++) {
            int bit = 0;
            for (char ch : words[i]) {
                // Har character ke liye uska bit set karna
                bit |= (1 << (ch - 'a'));
            }
            mask[i] = bit;              // Word ka bitmask store kiya
            len[i] = words[i].length(); // Word ki length store ki
        }

        // Step 2: Sabhi word pairs ko compare karo
        int maxProd = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Agar dono words ke letters disjoint hain
                if ((mask[i] & mask[j]) == 0) {
                    // Tabhi product calculate karo
                    int prod = len[i] * len[j];
                    maxProd = max(maxProd, prod);
                }
            }
        }

        return maxProd; // Final max product return karo
    }
};

int main() {
    Solution sol;
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << "Maximum Product: " << sol.maxProduct(words) << endl;
    return 0;
}

/*
================ DRY RUN ================

Input:
words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"}

Step 1: Create Bitmasks
------------------------
"abcw"   → bitmask: letters a,b,c,w = 00000000000000000000010000000111
"baz"    → bitmask: letters b,a,z   = 10000000000000000000000000000011
"foo"    → bitmask: letters f,o     = 00000000000000001000000100000000
"bar"    → bitmask: letters b,a,r   = 00000000000000000010000000000011
"xtfn"   → bitmask: x,t,f,n         = 00000000010001000000010000000000
"abcdef" → bitmask: a,b,c,d,e,f     = 00000000000000000000000000111111

Step 2: Compare pairs and find max product
------------------------------------------
- "abcw" × "xtfn"   → Disjoint ✅ → 4×4 = 16 → max = 16
- "abcw" × others   → Common letters ❌
- "abcdef" × "xtfn" → Disjoint ✅ → 6×4 = 24 → max = 24

Final Output:
Maximum Product: 24
*/
