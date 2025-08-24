#include <bits/stdc++.h>
using namespace std;

/*
    Problem: LeetCode 264 - Ugly Number II
    An ugly number is a number whose prime factors are only 2, 3, and 5.
    The sequence of ugly numbers starts with:
    1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
    
    Task:
    Given an integer n, return the nth ugly number.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        // DP array to store ugly numbers
        vector<int> ugly(n);
        ugly[0] = 1; // First ugly number is always 1

        // Pointers for multiples of 2, 3, and 5
        int p2 = 0, p3 = 0, p5 = 0;

        // Generate ugly numbers from 2nd to nth
        for (int i = 1; i < n; i++) {
            // Possible next ugly numbers
            int next2 = ugly[p2] * 2;
            int next3 = ugly[p3] * 3;
            int next5 = ugly[p5] * 5;

            // Choose the smallest
            int nextUgly = min({next2, next3, next5});
            ugly[i] = nextUgly;

            // Move the pointer(s) that matched
            if (nextUgly == next2) p2++;
            if (nextUgly == next3) p3++;
            if (nextUgly == next5) p5++;
        }

        // Return the nth ugly number
        return ugly[n - 1];
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    // Output the nth ugly number
    cout << "The " << n << "th ugly number is: " 
         << sol.nthUglyNumber(n) << endl;

    return 0;
}

/*
    Example Run:
    Input: 10
    Output: 12

    Explanation:
    First 10 ugly numbers are:
    1, 2, 3, 4, 5, 6, 8, 9, 10, 12
    So the 10th ugly number is 12.
*/
