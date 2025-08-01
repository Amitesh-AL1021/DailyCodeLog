#include <iostream>
#include <string>
#include <vector>
#include <limits> // for numeric_limits
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<string> arr;
    string temp;

    cout << "Enter " << n << " elements (space-separated):\n";

    // ✅ Input loop: only accept up to n inputs
    while (arr.size() < n && cin >> temp) {
        arr.push_back(temp);
    }

    // ✅ Check for extra input
    if (cin.peek() != '\n') {
        cout << "⚠️ Warning: You entered more than " << n << " elements. Extra input ignored.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush extra inputs
    }

    // ✅ Convert '.' to '[.]' and build final string
    string ans = "";
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == ".") {
            ans += "[.]";
        } else {
            ans += arr[i];
        }
    }

    cout << "✅ Result: " << ans << endl;
    return 0;
}
