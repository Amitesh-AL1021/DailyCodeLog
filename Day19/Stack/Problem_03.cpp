#include <iostream>       // For input/output
#include <vector>         // For vector
#include <stack>          // For stack
#include <unordered_map>  // For hash map
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m; // Map to store: number → next greater number
        stack<int> s;              // Stack to keep numbers in decreasing order

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Remove all elements from stack that are smaller or equal to current number
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            // If stack is empty → no greater number on the right
            if (s.empty()) {
                m[nums2[i]] = -1;
            }
            // Else → stack top is the next greater number
            else {
                m[nums2[i]] = s.top();
            }

            // Push current number onto stack
            s.push(nums2[i]);
        }

        // Build the result for nums1 using the precomputed map
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*
====================== DRY RUN ======================

nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]

Step 1: Build mapping using nums2 (traverse from right to left)

i = 3, nums2[i] = 2
    Stack empty → m[2] = -1
    Push 2 → stack: [2]

i = 2, nums2[i] = 4
    Pop 2 (<= 4) → stack empty
    Stack empty → m[4] = -1
    Push 4 → stack: [4]

i = 1, nums2[i] = 3
    Top 4 > 3 → stop popping
    m[3] = 4
    Push 3 → stack: [4, 3]

i = 0, nums2[i] = 1
    Top 3 > 1 → stop popping
    m[1] = 3
    Push 1 → stack: [4, 3, 1]

Map m after processing:
    m[1] = 3
    m[3] = 4
    m[4] = -1
    m[2] = -1

Step 2: Build result for nums1
    nums1[0] = 4 → m[4] = -1
    nums1[1] = 1 → m[1] = 3
    nums1[2] = 2 → m[2] = -1

Final Output: [-1, 3, -1]
======================================================
*/
