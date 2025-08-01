#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start filling from the end of nums1
        int idx = m + n - 1; // Final index for merged array
        int i = m - 1;       // Pointer for nums1 (excluding 0 placeholders)
        int j = n - 1;       // Pointer for nums2

        // Merge from the end to avoid overwriting valid nums1 data
        while(i >= 0 && j >= 0) {
            if(nums1[i] >= nums2[j]) {
                nums1[idx--] = nums1[i--];  // Place nums1[i] at idx, move both pointers
            } else {
                nums1[idx--] = nums2[j--];  // Place nums2[j] at idx, move both pointers
            }
        }

        // If any elements left in nums2, copy them
        // (No need to copy nums1 leftovers; they’re already in place)
        while(j >= 0) {
            nums1[idx--] = nums2[j--];
        }
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};  // First sorted array with extra space
    int m = 3;

    vector<int> nums2 = {2, 5, 6};           // Second sorted array
    int n = 3;

    // Call merge function
    solution.merge(nums1, m, nums2, n);

    // Output the merged array
    cout << "Merged array: ";
    for(int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
