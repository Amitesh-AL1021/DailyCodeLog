#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(num, target, 0, "", 0, 0, res);
        return res;
    }

private:
    void backtrack(string& num, int target, int index, string path,
                   long long value, long long prev, vector<string>& res) {
        // ✅ Base case: All digits used and value matches target
        if (index == num.size()) {
            if (value == target) {
                res.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.size(); ++i) {
            // 🚫 Skip numbers with leading zero
            if (i != index && num[index] == '0') break;

            string curr_str = num.substr(index, i - index + 1);
            long long curr_num = stoll(curr_str);

            if (index == 0) {
                // First number, don't add an operator
                backtrack(num, target, i + 1, curr_str, curr_num, curr_num, res);
            } else {
                // ➕ Addition
                backtrack(num, target, i + 1, path + "+" + curr_str, value + curr_num, curr_num, res);

                // ➖ Subtraction
                backtrack(num, target, i + 1, path + "-" + curr_str, value - curr_num, -curr_num, res);

                // ✖️ Multiplication (handle precedence)
                backtrack(num, target, i + 1, path + "*" + curr_str,
                          value - prev + prev * curr_num, prev * curr_num, res);
            }
        }
    }
};
int main() {
    Solution s;
    vector<string> result = s.addOperators("123", 6);
    for (const string& expr : result) {
        cout << expr << endl;
    }
    return 0;
}
