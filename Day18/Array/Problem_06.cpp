#include<iostream>
using namespace std;

int main() {
    // Step 1: Declare and initialize an array of 6 integers
    int arr[6] = {1, 2, 3, 4, 5, 6};

    // Step 2: Initialize two pointers for reversing
    // 'start' points to the beginning of the array
    // 'end' points to the last index of the array
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1; // safer way to calculate last index

    // Step 3: Swap elements from start and end until they meet
    while(start < end) {
        // Swap the values at positions 'start' and 'end'
        swap(arr[start], arr[end]);

        // Move 'start' forward and 'end' backward
        start++;
        end--;
    }

    // Step 4: Print the reversed array
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
