#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the total number (n): ";
    cin >> n;

    int arr[n-1];
    cout << "Enter " << n-1 << " numbers from 1 to " << n << " (one number is missing):" << endl;

    // ✅ Take input from user
    for(int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    // ✅ Sum of elements entered
    int sum = 0;
    for(int i = 0; i < n-1; i++) {
        sum += arr[i];
    }

    // ✅ Total sum of 1 to n
    int total = n * (n + 1) / 2;

    // ✅ Find missing number
    int missing = total - sum;
    cout << "Missing number is: " << missing << endl;

    return 0;
}
