#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to move all zeros to the end while maintaining the order of non-zero elements
    void moveZeroes(vector<int>& nums) {
        int indexnonzero = 0;  // This will point to the position where the next non-zero should be placed

        // First pass: Shift non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[indexnonzero] = nums[i];  // Place the non-zero at the correct position
                indexnonzero++;  // Move the pointer to next index
            }
        }

        // Second pass: Fill the rest of the array with zeroes
        for (int i = indexnonzero; i < nums.size(); i++) {
            nums[i] = 0;  // All positions after indexnonzero should be set to 0
        }
    }
};

int main() {
    Solution so;
    vector<int> nums = {0, 1, 0, 3, 12};

    so.moveZeroes(nums);

    // Output the modified array
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}

/*
==================== DRY RUN ====================

Initial array: {0, 1, 0, 3, 12}
indexnonzero = 0

First pass (moving non-zeros):
i = 0: nums[0] == 0 → skip
i = 1: nums[1] == 1 → nums[0] = 1 → indexnonzero = 1
       Updated array: {1, 1, 0, 3, 12}
i = 2: nums[2] == 0 → skip
i = 3: nums[3] == 3 → nums[1] = 3 → indexnonzero = 2
       Updated array: {1, 3, 0, 3, 12}
i = 4: nums[4] == 12 → nums[2] = 12 → indexnonzero = 3
       Updated array: {1, 3, 12, 3, 12}

Second pass (filling remaining with 0):
i = 3 → nums[3] = 0
       Updated array: {1, 3, 12, 0, 12}
i = 4 → nums[4] = 0
       Final array:   {1, 3, 12, 0, 0}

================== FINAL OUTPUT ==================
1 3 12 0 0

Time Complexity  : O(n)
Space Complexity : O(1) → In-place modification, no extra space used

==================================================
*/
