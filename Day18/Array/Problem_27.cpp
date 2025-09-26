#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> result;

        // Count frequency of elements in nums1
        for (int num : nums1) {
            freq[num]++;
        }

        // Check elements in nums2
        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;  // decrease count
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> ans = sol.intersect(nums1, nums2);

    cout << "Intersection: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
