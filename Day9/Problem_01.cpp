#include <iostream>
#include <vector>
using namespace std;

/*
Approach: Start from the top-right corner of the matrix.

Why top-right?
- From top-right:
    - If the element is greater than the target, move LEFT (since all elements to the left are smaller).
    - If the element is smaller than the target, move DOWN (since all elements below are bigger).
    
Time Complexity: O(m + n), where m is number of rows, n is number of columns
Space Complexity: O(1), no extra space used
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;

        // Start from top-right corner
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                return true; // target found
            } else if (matrix[row][col] > target) {
                col--; // move left
            } else {
                row++; // move down
            }
        }
        return false; // target not found
    }
};

// Sample main function for testing in VS Code
int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 60;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}
