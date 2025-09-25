#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return true; // duplicate found
            seen.insert(num);
        }
        return false; // no duplicate
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};
    
    cout << "Test case 1: " << (sol.containsDuplicate(nums1) ? "true" : "false") << endl;
    cout << "Test case 2: " << (sol.containsDuplicate(nums2) ? "true" : "false") << endl;
    cout << "Test case 3: " << (sol.containsDuplicate(nums3) ? "true" : "false") << endl;

    return 0;
}
