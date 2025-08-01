#include<iostream>  // Input/output ke liye header file include kar rahe hain
using namespace std;  // Standard C++ namespace use kar rahe hain

int main() {
    int n;

    // Step 1: User se array ka size lena
    cout << "Enter your number : ";
    cin >> n;

    // Step 2: Array declare karna
    // ⚠️ Yeh variable length array hai (C++ standard mein allowed nahi, lekin GCC compiler mein kaam karta hai)
    int arr[n];

    // Step 3: User se array ke elements lena
    cout << "Enter " << n << " elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];  // Har element input leke array mein store karna
    }

    // Step 4: Maximum nikalne ke liye initial value ko INT16_MIN se set karte hain
    // Interview mein explain karo: INT16_MIN ek macro hai jiska value -32768 hota hai
    // Yeh assume karta hai ki array ka maximum element isse bada hi hoga
    int ans = INT16_MAX;

    // Step 5: Array traverse karke maximum element dhoondhna
    for(int i = 0; i < n; i++) {
        // Agar current element ans se bada hai, toh usse ans mein update kar do
        if(arr[i] < ans) {
            ans = arr[i];
        }
    }

    // Step 6: Result print karna
    cout << "Minimum element in the array is : " << ans;

    return 0;  // Program successful end
}
