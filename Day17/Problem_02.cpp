#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int total = 0, curr = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curr += 1;       // extend previous arithmetic slice
                total += curr;   // add to total
            } else {
                curr = 0;        // reset if not arithmetic
            }
        }
        return total;
    }
};

int main() {
    Solution sol;

    // Take input from user
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.numberOfArithmeticSlices(nums);
    cout << "Number of Arithmetic Slices: " << result << endl;

    return 0;
}
