#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Main function to check if a number is an additive sequence
    bool isAdditiveNumber(string num) {
        int n = num.length();

        // Try all combinations of first and second numbers
        for (int i = 1; i <= n / 2; ++i) {
            if (num[0] == '0' && i > 1) break; // Leading zero in first number

            string num1 = num.substr(0, i);

            for (int j = 1; max(i, j) <= n - i - j; ++j) {
                if (num[i] == '0' && j > 1) break; // Leading zero in second number

                string num2 = num.substr(i, j);
                string remaining = num.substr(i + j);

                if (isValid(num1, num2, remaining))
                    return true;
            }
        }
        return false;
    }

private:
    // Add two large numbers in string format
    string addStrings(string a, string b) {
        string result = "";
        int carry = 0, i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            result = char(sum % 10 + '0') + result;
        }

        return result;
    }

    // Check if the additive sequence is valid
    bool isValid(string num1, string num2, string remaining) {
        while (!remaining.empty()) {
            string sum = addStrings(num1, num2);

            if (remaining.find(sum) != 0)
                return false;

            remaining = remaining.substr(sum.length());
            num1 = num2;
            num2 = sum;
        }
        return true;
    }
};

// ---------- Example usage ----------
int main() {
    Solution sol;

    // Example 1: Input: "112358"
    // Sequence: 1, 1, 2, 3, 5, 8 (Valid)
    // Output: true
    cout << boolalpha << sol.isAdditiveNumber("112358") << endl;  // true

    // Example 2: Input: "199100199"
    // Sequence: 199, 100, 299 -> then 100, 299, 399 -> Valid
    // Output: true
    cout << boolalpha << sol.isAdditiveNumber("199100199") << endl;  // true

    return 0;
};