# 🧮 LeetCode Problem 1: Two Sum

## 1. 📄 Problem Explanation

You are given an array of integers `nums` and an integer `target`. Your task is to find **two distinct indices** `i` and `j` such that:


Each input will have exactly one valid solution. You **cannot use the same element twice**, and you should return the indices in any order.

---

## 2. ✅ Approach

We use a **hash map** to store elements as we iterate. At every index `i`, we check whether the **complement** (`target - nums[i]`) exists in the hash map. If it does, we return its index and the current index.

This way, we only need **one pass** through the array and can find the solution in **linear time**.

---

## 3. 🧠 Algorithm

1. Initialize an empty hash map `mp` to store value → index.
2. Iterate through each element in `nums` using index `i`:
   - Calculate the complement: `remaining = target - nums[i]`
   - If `remaining` is already in the map, return `[mp[remaining], i]`
   - Otherwise, store `nums[i]` in the map with its index
3. The loop will always return a result because one valid answer is guaranteed.

---

## 4. ⏱ Time and Space Complexity

| Complexity | Explanation                              |
|------------|------------------------------------------|
| ⌛ Time     | **O(N)** - Loop through the array once   |
| 🧠 Space    | **O(N)** - Storing up to N elements in map |

Where `N` is the length of the input array `nums`.

---


Each input will have exactly one valid solution. You **cannot use the same element twice**, and you should return the indices in any order.

---

## 2. ✅ Approach

We use a **hash map** to store elements as we iterate. At every index `i`, we check whether the **complement** (`target - nums[i]`) exists in the hash map. If it does, we return its index and the current index.

This way, we only need **one pass** through the array and can find the solution in **linear time**.

---

## 3. 🧠 Algorithm

1. Initialize an empty hash map `mp` to store value → index.
2. Iterate through each element in `nums` using index `i`:
   - Calculate the complement: `remaining = target - nums[i]`
   - If `remaining` is already in the map, return `[mp[remaining], i]`
   - Otherwise, store `nums[i]` in the map with its index
3. The loop will always return a result because one valid answer is guaranteed.

---

## 4. ⏱ Time and Space Complexity

| Complexity | Explanation                              |
|------------|------------------------------------------|
| ⌛ Time     | **O(N)** - Loop through the array once   |
| 🧠 Space    | **O(N)** - Storing up to N elements in map |

Where `N` is the length of the input array `nums`.

---

## 5. 💻 C++ Code (with Comments)

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store number and its index
        unordered_map<int, int> mp;

        // Loop through each element
        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];

            // If complement exists in map, we found the pair
            if (mp.find(remaining) != mp.end()) {
                return {mp[remaining], i};
            }

            // Store current number with its index
            mp[nums[i]] = i;
        }

        return {}; // Should never reach here as per problem statement
    }
};


# 📘 Day 1 – 14 July 2025

## 🧠 Problems Solved:

| Problem No. | Title              | Code File           | Explanation |
|-------------|--------------------|----------------------|-------------|
| 1           | Two Sum            | [Problem_01.cpp](./Problem_01.cpp) | [README_01.md](./README_01.md) |
| 2           | Add Digits         | [Problem_02.cpp](./Problem_02.cpp) | [README_02.md](./README_02.md) |
| 3           | Merge Sorted Array | [Problem_03.cpp](./Problem_03.cpp) | [README_03.md](./README_03.md) |
| 4           | Reverse Integer    | [Problem_04.cpp](./Problem_04.cpp) | [README_04.md](./README_04.md) |
