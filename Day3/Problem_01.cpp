#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;

            // Check for 32-bit signed integer overflow
            if (reversed > INT_MAX || reversed < INT_MIN) {
                return 0;
            }

            x /= 10;
        }

        return static_cast<int>(reversed);
    }
};

// Driver Code (For testing)
int main() {
    Solution sol;
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Reversed integer: " << sol.reverse(num) << endl;
    return 0;
}
