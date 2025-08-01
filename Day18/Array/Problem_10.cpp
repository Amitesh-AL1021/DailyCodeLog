#include<iostream>
using namespace std;

// 🔹 Program: Rotate the array by 1 position to the right
// ---------------------------------------------------------
// Example:
// Input:  [1, 2, 3, 4, 5]
// Output: [5, 1, 2, 3, 4]

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    int arr[100];  // Assuming max size is 100
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 1: Store last element
    int last = arr[n - 1];

    // Step 2: Shift elements one step to right
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Step 3: Put last element at first position
    arr[0] = last;

    // Print rotated array
    cout << "Array after rotating by 1: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
