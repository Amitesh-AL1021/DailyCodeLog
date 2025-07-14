# ⚖️ LeetCode Problem 4: Median of Two Sorted Arrays

## 1. 📄 Problem Explanation

You are given two sorted arrays `nums1` and `nums2` of size `m` and `n`, respectively. The task is to return the **median** of the two sorted arrays.

The overall runtime complexity should be **O(log(min(m, n)))**.

### 🔹 Example:

---

## 2. ✅ Approach

### 👉 Brute Force (Simple Method - Used Here):
1. Merge both arrays into a single sorted array.
2. If the combined length is odd, return the middle element.
3. If it's even, return the average of the two middle elements.

This approach is **not optimal** in terms of time complexity, but it's clear and easy to understand.

---

## 3. 🧠 Algorithm

1. Create a new array `merged` to hold the merged result of `nums1` and `nums2`.
2. Use two pointers (`i` for `nums1`, `j` for `nums2`) to merge them in sorted order.
3. Once merged:
   - If total length is **odd**, return `merged[n / 2]`.
   - If total length is **even**, return average of `merged[n/2 - 1]` and `merged[n/2]`.

---

## 4. ⏱ Time and Space Complexity

| Complexity | Explanation                                        |
|------------|----------------------------------------------------|
| ⌛ Time     | **O(m + n)** – Merging both arrays takes linear time |
| 🧠 Space    | **O(m + n)** – We use extra space to store merged array |

> ✅ Note: There is a more optimal solution using binary search with **O(log(min(m, n)))** time, but that is more complex.

---

## 5. 💻 C++ Code (with Comments)

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;

        // Merge both arrays into one sorted array
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                merged.push_back(nums1[i++]);
            else
                merged.push_back(nums2[j++]);
        }

        // Append remaining elements
        while (i < nums1.size()) merged.push_back(nums1[i++]);
        while (j < nums2.size()) merged.push_back(nums2[j++]);

        int n = merged.size();

        // If odd, return middle
        if (n % 2 == 1) return merged[n / 2];

        // If even, return average of two middle values
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
};
