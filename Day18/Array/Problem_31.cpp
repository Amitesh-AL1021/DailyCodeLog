#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Step 1: Sort by height descending, then k ascending
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> queue;
        // Step 2: Insert each person at index = k
        for (auto& person : people) {
            queue.insert(queue.begin() + person[1], person);
        }

        return queue;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> ans = sol.reconstructQueue(people);

    cout << "Reconstructed Queue: ";
    for (auto &p : ans) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << endl;

    return 0;
}
