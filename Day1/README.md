# 📘 Day 1 – 14 July 2025 – LeetCode #1 Two Sum

## 🔗 Problem Link:
[https://leetcode.com/problems/two-sum](https://leetcode.com/problems/two-sum)

## ✅ Full C++ Code:

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        if (map.find(diff) != map.end())
            return {map[diff], i};
        map[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Indices: " << result[0] << " and " << result[1] << endl;
    return 0;
}
```
