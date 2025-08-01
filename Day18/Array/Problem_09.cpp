// #include<iostream>
// using namespace std;

// // 🔹 Program 1: Find the Nth Fibonacci number using an array
// // -------------------------------------------------------------
// // Yeh program ek array me pehle n Fibonacci numbers ko store karta hai
// // aur last wale (n-1 index pe jo hota hai) Fibonacci number ko print karta hai.

// int main() {
//     int n;
//     cout << "Enter the number : ";
//     cin >> n;

//     int arr[1000];          // Max 1000 Fibonacci numbers store karne ki space
//     arr[0] = 0;             // 0th Fibonacci number
//     arr[1] = 1;             // 1st Fibonacci number

//     for (int i = 2; i <= n - 1; i++) {
//         arr[i] = arr[i - 1] + arr[i - 2]; // Classic Fibonacci logic
//     }

//     cout << "The " << n << "th Fibonacci number is: " << arr[n - 1] << endl;
//     return 0;
// }

#include<iostream>
using namespace std;

// 🔹 Program 2: Print first N Fibonacci numbers (Fibonacci series)
// ------------------------------------------------------------------
// Yeh program bina array ke directly pehle n Fibonacci numbers ko print karta hai
// Yeh iterative method hai, memory efficient bhi hai.

int main() {
    int n;
    cout << "Enter your number : ";
    cin >> n;

    int a = 0, b = 1;
    int c = 0;

    cout << "Fibonacci series: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;  // next number
        a = b;
        b = c;
    }

    return 0;
}
