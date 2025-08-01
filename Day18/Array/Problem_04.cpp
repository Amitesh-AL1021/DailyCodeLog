#include<iostream>  // Input Output stream include karte hain
using namespace std;  // Standard namespace use kar rahe hain

int main() {
    int n;

    // Step 1: User se array ka size lena
    cout << "Enter the size of array : ";
    cin >> n;

    // Step 2: Array declare karna (size user ke input ke hisaab se)
    // ⚠️ Yeh Variable Length Array hai, jo standard C++ mein allowed nahi hai (lekin GCC compiler pe chalega)
    int arr[n];

    // Step 3: Array ke elements user se lena
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Har index pe user ka input store karna
    }
    int anssize = sizeof(arr)/sizeof(arr[0]);
    cout<<"size of array : "<<anssize<< endl;

    return 0;  // Program end
}
