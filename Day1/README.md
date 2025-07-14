# Day 1 - 14 July 2025 
## Problem Solved 
### Solution in C++
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Step 1: Create a hashmap to store values and their indices
        unordered_map<int, int> map;

        // Step 2: Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];              // current element
            int complement = target - current;  // what we need to reach target

            // Step 3: Check if complement exists in map
            if (map.find(complement) != map.end()) {
                // Found the pair! Return indices
                return {map[complement], i};
            }

            // Step 4: Otherwise, store current element in map
            // Key = number, Value = index
            map[current] = i;
        }

        // If no pair found (shouldn't happen as per problem guarantee)
        return {};
    }
};


