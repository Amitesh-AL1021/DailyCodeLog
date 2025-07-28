#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Step 1: Convert all integers to strings
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Step 2: Custom comparator
        // We sort based on which combination gives a larger number: (a+b vs b+a)
        sort(strNums.begin(), strNums.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // Step 3: Edge case - if the largest number is "0", then all are zero
        if (strNums[0] == "0") {
            return "0";
        }

        // Step 4: Concatenate all strings to form the final result
        string result = "";
        for (string &s : strNums) {
            result += s;
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> nums = {3, 30, 34, 5, 9};
    
    // Get the largest number formed by the list
    string result = sol.largestNumber(nums);
    
    // Output the result
    cout << "Largest Number: " << result << endl;

    return 0;
}
