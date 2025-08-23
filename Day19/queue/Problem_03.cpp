#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = (int)score.size();
        vector<pair<int,int>> a;  // {score, index}
        a.reserve(n);
        
        for (int i = 0; i < n; ++i) 
            a.push_back({score[i], i});

        // Sort in descending order of score
        sort(a.begin(), a.end(), [](const auto& x, const auto& y){
            return x.first > y.first;
        });

        vector<string> ans(n);
        for (int rank = 0; rank < n; ++rank) {
            int idx = a[rank].second;
            if (rank == 0) ans[idx] = "Gold Medal";
            else if (rank == 1) ans[idx] = "Silver Medal";
            else if (rank == 2) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(rank + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> scores = {10, 3, 8, 9, 4};

    // Call function
    vector<string> result = sol.findRelativeRanks(scores);

    // Print output
    cout << "Relative Ranks: " << endl;
    for (string &s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
