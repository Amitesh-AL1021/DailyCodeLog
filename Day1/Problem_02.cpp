#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;

        int first = 1, second = 1, result = 0;

        for (int i = 2; i <= n; i++) {
            result = first + second;
            first = second;
            second = result;
        }

        return result;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter number of steps: ";
    cin >> n;

    cout << "Number of distinct ways to climb " << n << " steps: " << sol.climbStairs(n) << endl;

    return 0;
}
