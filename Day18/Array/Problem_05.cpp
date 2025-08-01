#include<iostream>
#include<vector>
#include<limits> // cin.ignore ke liye
using namespace std;

int main() {
    int n, x;

    // Step 1: Array ka size lo
    cout << "Array ka size daalo: ";
    cin >> n;

    // Agar size galat diya toh exit kar jaao
    if(n <= 0) {
        cout << "❌ Galat size! Size 0 ya negative nahi ho sakta." << endl;
        return 1;
    }

    // Step 2: Array banaye aur user se element lo
    vector<int> arr(n);
    cout << "Ab " << n << " elements daalo (space ya enter se alag karo): ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Agar user ne zyada input de diya ho toh usse hatao
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Step 4: Ab search karne wala number lo
    cout << "Ab jo number search karna hai wo daalo: ";
    cin >> x;

    // Step 5: Flag banao ye check karne ke liye ki number mila ya nahi
    bool found = false;

    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            found = true;
            break;  // Mil gaya toh loop chhodo
        }
    }

    // Step 6: Output do based on result
    if(found)
        cout << "✅ Haan! Number array mein maujood hai." << endl;
    else
        cout << "❌ Nahi! Number array mein nahi hai." << endl;

    return 0;
}
