#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1; // Start with 1 slot for the root
        string node;
        stringstream ss(preorder);

        while (getline(ss, node, ',')) { // Split the string by commas
            slots--; // Every node consumes 1 slot

            if (slots < 0) return false; // If no slot is available → invalid

            if (node != "#") 
                slots += 2; // Non-null node adds 2 child slots
        }

        return slots == 0; // Valid if all slots are used exactly
    }
};

int main() {
    Solution sol;
    string preorder;
    cout << "Enter preorder serialization: ";
    cin >> preorder;

    if (sol.isValidSerialization(preorder))
        cout << "Valid serialization\n";
    else
        cout << "Invalid serialization\n";

    return 0;
}

/*
Dry Run Example:

Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"

Step by Step:

1. slots = 1
2. Read '9' → slots-- (0), node != '#' → slots +=2 → slots = 2
3. Read '3' → slots-- (1), node != '#' → slots +=2 → slots = 3
4. Read '4' → slots-- (2), node != '#' → slots +=2 → slots = 4
5. Read '#' → slots-- (3)
6. Read '#' → slots-- (2)
7. Read '1' → slots-- (1), node != '#' → slots +=2 → slots = 3
8. Read '#' → slots-- (2)
9. Read '#' → slots-- (1)
10. Read '2' → slots-- (0), node != '#' → slots +=2 → slots = 2
11. Read '#' → slots-- (1)
12. Read '6' → slots-- (0), node != '#' → slots +=2 → slots = 2
13. Read '#' → slots-- (1)
14. Read '#' → slots-- (0)

Final slots = 0 → Serialization is valid.
*/
