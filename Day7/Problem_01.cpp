#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;

        // Arrays to store the frequency of digits (0-9) that did not match in position
        vector<int> s(10, 0); // For secret
        vector<int> g(10, 0); // For guess

        // Loop through each character of both strings
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                // If both characters match at the same position → it's a bull
                bulls++;
            } else {
                // Otherwise, store digit frequencies for cow check later
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }

        // Calculate cows: digits that match but are in the wrong position
        for (int i = 0; i < 10; ++i) {
            // Minimum of matched digits in secret and guess gives count of cows for that digit
            cows += min(s[i], g[i]);
        }

        // Return the final hint in format: "xAyB"
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    Solution sol;

    // Test case 1
    string secret = "1807";
    string guess = "7810";

    // Get the hint from the function
    string result = sol.getHint(secret, guess);

    // Output the result
    cout << "Secret: " << secret << "\n";
    cout << "Guess : " << guess << "\n";
    cout << "Hint  : " << result << "\n"; // Expected: "1A3B"

    return 0;
}
