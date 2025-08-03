#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the single number (appears only once)
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        // Traverse each element in the array
        for(int varrr : nums) {
            // XOR the current number with the result
            ans = ans ^ varrr;
        }

        // The result contains the number that appears only once
        return ans;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> nums = {4, 1, 2, 1, 2};

    // Output the single number
    cout << "Single Number is: " << obj.singleNumber(nums) << endl;

    return 0;
}

/*
🔍 Dry Run for Input: {4, 1, 2, 1, 2}

Initial ans = 0

Step 1: ans = 0 ^ 4 = 4
Step 2: ans = 4 ^ 1 = 5
Step 3: ans = 5 ^ 2 = 7
Step 4: ans = 7 ^ 1 = 6
Step 5: ans = 6 ^ 2 = 4

✅ Final Output: 4
(This is the number that appears only once. Others cancel out using XOR.)
*/
