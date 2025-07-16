#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};

    int result = sol.singleNumber(nums);
    cout << "The number that appears only once is: " << result << endl;

    return 0;
}
