#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();

        // Step 1: Find the pivot (first number from right that is smaller than the next one)
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot found, array is in descending order => reverse it
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the next greater element to the right of pivot and swap
        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse the suffix (elements right of the pivot)
        int i = pivot + 1, j = n - 1;
        while(i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3};  // Example input

    cout << "Original permutation: ";
    for(int num : nums) cout << num << " ";
    cout << endl;

    solution.nextPermutation(nums);  // Find next permutation

    cout << "Next permutation: ";
    for(int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}

/*
🔁 Dry Run for Input: [1, 2, 3]

Initial Array: [1, 2, 3]

Step 1: Find Pivot
    - i = 1 → nums[1] = 2 < nums[2] = 3 → pivot = 1

Step 2: Find Next Greater Element to the Right
    - i = 2 → nums[2] = 3 > nums[1] = 2 → swap(nums[1], nums[2])
    - Array becomes: [1, 3, 2]

Step 3: Reverse Suffix After Pivot (pivot = 1)
    - Suffix = [2]
    - Reversing it → No change
    - Final Array = [1, 3, 2]

Output: Next permutation = [1, 3, 2]
*/
