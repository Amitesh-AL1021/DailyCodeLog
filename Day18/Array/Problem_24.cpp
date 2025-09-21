#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }

    void update(int index, int value) {
        for (; index <= n; index += index & -index)
            tree[index] += value;
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index)
            sum += tree[index];
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // Coordinate compression
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        for (int i = 0; i < sorted.size(); i++) {
            rank[sorted[i]] = i + 1; // 1-based indexing for Fenwick tree
        }

        FenwickTree BIT(sorted.size());
        vector<int> result(nums.size());

        // Traverse from right to left
        for (int i = nums.size() - 1; i >= 0; i--) {
            int pos = rank[nums[i]];
            result[i] = BIT.query(pos - 1);
            BIT.update(pos, 1);
        }

        return result;
    }
};

#pragma GCC optimize("O2")

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = sol.countSmaller(nums);

    cout << "Output: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
