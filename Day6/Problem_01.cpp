#include <iostream>
#include <vector>
#include <algorithm>  // for std::min and std::max

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // Calculate current area
            int current_area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, current_area);

            // Move the pointer pointing to the smaller height
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Maximum water container area: " << sol.maxArea(height) << endl;
    return 0;
}
