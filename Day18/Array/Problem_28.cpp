#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
        bool hasFirst = false, hasSecond = false, hasThird = false;

        for (long long x : nums) {
            if ((hasFirst && x == first) || (hasSecond && x == second) || (hasThird && x == third))
                continue;
            if (!hasFirst || x > first) {
                third = second; hasThird = hasSecond;
                second = first; hasSecond = hasFirst;
                first = x; hasFirst = true;
            } else if (!hasSecond || x > second) {
                third = second; hasThird = hasSecond;
                second = x; hasSecond = true;
            } else if (!hasThird || x > third) {
                third = x; hasThird = true;
            }
        }

        return hasThird ? (int)third : (int)first;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 2, 3, 1};  // <-- change input here

    int result = sol.thirdMax(nums);
    cout << "Third maximum (or max if not exists): " << result << endl;

    return 0;
}
