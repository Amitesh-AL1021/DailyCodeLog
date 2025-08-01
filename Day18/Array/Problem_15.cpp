//  // Two Sum Problem 
//  class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 // Check if pair sum equals the target
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j}; // Return indices as vector
//                 }
//             }
//         }
//         return {}; // Return empty vector if no pair found
//     }
// };







// #include <iostream>
// #include <vector>
// #include <algorithm> // For sort
// using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();

//         // Step 1: Create a vector of pairs: {value, original index}
//         vector<pair<int, int>> arr;
//         for (int i = 0; i < n; i++) {
//             arr.push_back({nums[i], i}); // Store both value and its index
//         }

//         // Step 2: Sort the array based on the value (not index)
//         sort(arr.begin(), arr.end());

//         // Step 3: Initialize two pointers
//         int start = 0;       // Pointer at beginning
//         int end = n - 1;     // Pointer at end

//         // Step 4: Loop until start < end
//         while (start < end) {
//             int sum = arr[start].first + arr[end].first;  // Sum of values

//             if (sum == target) {
//                 // If the sum matches the target, return the original indices
//                 return {arr[start].second, arr[end].second};
//             }
//             else if (sum < target) {
//                 // If sum is less than target, move start forward to increase sum
//                 start++;
//             }
//             else {
//                 // If sum is greater than target, move end backward to decrease sum
//                 end--;
//             }
//         }

//         // If no pair is found (though problem guarantees one), return empty vector
//         return {};
//     }
// };

// int main() {
//     Solution sol;

//     // Sample input
//     vector<int> nums = {2, 7, 11, 15};
//     int target = 9;

//     // Call the function and get the result
//     vector<int> result = sol.twoSum(nums, target);

//     // Output the result
//     cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;

//     return 0;
// }
