#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        
        // If less than 2 elements, no gap can be formed
        if (n < 2) return 0;

        // Step 1: Find the minimum and maximum values in the array
        int mini = INT_MAX, maxi = INT_MIN;
        for (int num : nums) {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }

        // If all numbers are the same, gap is zero
        if (mini == maxi) return 0;

        // Step 2: Calculate bucket size and number of buckets
        int bucketSize = max(1, (maxi - mini) / (n - 1));
        int bucketCount = ((maxi - mini) / bucketSize) + 1;

        // Step 3: Create buckets to store min and max values for each bucket
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> isBucketUsed(bucketCount, false);

        // Step 4: Place each number into its appropriate bucket
        for (int num : nums) {
            int idx = (num - mini) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            isBucketUsed[idx] = true;
        }

        // Step 5: Traverse through the buckets to find the maximum gap
        int maxGap = 0;
        int prevMax = mini;

        for (int i = 0; i < bucketCount; ++i) {
            if (!isBucketUsed[i]) continue;  // Skip empty buckets

            // The gap is the difference between current bucket's min and previous bucket's max
            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};
