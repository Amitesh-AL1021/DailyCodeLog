#include <iostream>
#include <vector>
using namespace std;

// Yeh function string ko arrange karega number ke hisaab se
string arrangeWords(string s) {
    vector<string> ans(10);  // 10 size ka vector bna rahe h jisme har word uski position pe store hoga (1-9 ke liye)
    string temp = "";        // Temporary string har word ko store karne ke liye
    int index = 0, count = 0;  // index loop ke liye aur count total words ko count karne ke liye

    // Loop chalayenge pura string par
    while (index < s.size()) {
        if (s[index] == ' ') {  // Agar space mila, matlab ek word complete ho gaya
            int pos = temp[temp.size() - 1] - '0';  // Last character ko digit me convert karo (e.g. '1' → 1)
            temp.pop_back();  // Last digit ko remove kar do word se
            ans[pos] = temp;  // Us position pe word ko vector me store karo
            temp.clear();     // temp ko clear karo agla word store karne ke liye
            count++;          // Ek word complete ho gaya, count++ kar do
        } else {
            temp += s[index];  // Jab tak space na aaye, temp me character add karte raho
        }
        index++;  // Index badhao
    }

    // Last word ko bhi process karna hoga (kyunki wo space ke baad nahi hota)
    if (!temp.empty()) {
        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[pos] = temp;
        count++;
    }

    // Final result banayenge sorted words se
    temp = "";  // temp ko ab result ke liye use karenge
    for (int i = 1; i <= count; i++) {
        temp += ans[i];   // i-th position ka word add karo
        temp += " ";      // Space lagao har word ke baad
    }

    temp.pop_back();  // Last extra space ko hata do
    return temp;      // Final string return karo
}

int main() {
    string input = "My1 name2 is3 amitesh4";  // Input sentence with number suffix
    string result = arrangeWords(input);     // Function call karke sorted sentence le lo
    cout << result << endl;                  // Output print karo
    return 0;
}
