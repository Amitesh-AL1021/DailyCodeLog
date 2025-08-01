// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         for(int var : nums){
//             int frq = 0;
//             for(int elm : nums){
//                 if(elm == var){
//                     frq++;
//                 }
//             }
//             if(frq > (n / 2)){
//                 return var;
//             }
//         }
//         return -1; // To handle compiler warning (though not needed per problem)
//     }
// };

// int main() {
//     vector<int> nums = {2, 2, 1, 1, 1,}; // Example input
//     Solution sol;
//     int result = sol.majorityElement(nums);

//     cout << "Majority element is: " << result << endl;

//     return 0;
// }











#include <iostream>
#include <vector>
using namespace std;

// Solution class with majorityElement method using Boyer-Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();  // Get size of array
        int frq = 0;          // Frequency counter
        int ans = 0;          // Variable to store potential majority element

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // If frequency is 0, set current element as candidate
            if (frq == 0) {
                ans = nums[i];
            }

            // If current element matches candidate, increase frequency
            if (ans == nums[i]) {
                frq++;
            } 
            // Else decrease frequency
            else {
                frq--;
            }
        }

        // Return the majority element
        return ans;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = sol.majorityElement(nums);

    cout << "The majority element is: " << result << endl;

    return 0;
}










// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//        int n = nums.size();
//       sort(nums.begin(),nums.end());
//       int frq = 1;
//       int ans = nums[0];
//       for(int i = 1 ; i <n; i++){
//         if(nums[i]==nums[i-1]){
//             frq++;
//         }
//         else{
//             frq = 1;
//             ans = nums[i];
//         }
//         if(frq>(n/2)){
//             return ans;
//         }
//       }

//     return ans;
//    }
// };