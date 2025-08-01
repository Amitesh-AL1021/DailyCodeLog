#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[4] = {4,4,4,4};

    // Step 1: Find the maximum
    int ans = INT_MIN;
    for(int i = 0; i < 4; i++){
        if(arr[i] > ans)
            ans = arr[i];
    }
    cout << "MAX : " << ans << " ";

    // Step 2: Find second maximum
    int second = INT_MIN;
    for(int i = 0; i < 4; i++){
        if(arr[i] != ans)
            second = max(second, arr[i]);
    }

    // ✅ Step 3: Check if second max was found or not
    if (second == INT_MIN)
        cout << "SECOND MAX : Not Found (All elements are equal)";
    else
        cout << "SECOND MAX : " << second;

    return 0; // ✅ return at the end
}
