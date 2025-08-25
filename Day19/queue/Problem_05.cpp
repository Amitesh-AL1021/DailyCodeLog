#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // Min-heap: {sum, i, j}
        auto cmp = [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, decltype(cmp)> minHeap(cmp);

        // Initialize heap with nums1[0] + nums2[j]
        for (int j = 0; j < (int)nums2.size() && j < k; j++) {
            minHeap.emplace(nums1[0] + nums2[j], 0, j);
        }

        while (k-- > 0 && !minHeap.empty()) {
            tuple<int,int,int> top = minHeap.top();
            minHeap.pop();

            int sum = get<0>(top);
            int i   = get<1>(top);
            int j   = get<2>(top);

            result.push_back({nums1[i], nums2[j]});

            if (i + 1 < (int)nums1.size()) {
                minHeap.emplace(nums1[i+1] + nums2[j], i+1, j);
            }
        }

        return result;
    }
};

// ==================== MAIN FUNCTION ====================
int main() {
    Solution sol;

    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    vector<vector<int>> ans = sol.kSmallestPairs(nums1, nums2, k);

    cout << "Smallest " << k << " pairs with smallest sums:\n";
    for (auto &p : ans) {
        cout << "[" << p[0] << ", " << p[1] << "]\n";
    }

    return 0;
}
