#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------
// Simulated LeetCode NestedInteger class
// ---------------------------------------------------
class NestedInteger {
    bool isInt;                  // true if holding a single integer
    int value;                   // integer value
    vector<NestedInteger> list;  // list of NestedInteger
public:
    // Constructors
    NestedInteger() : isInt(false), value(0) {}
    NestedInteger(int val) : isInt(true), value(val) {}

    // Return true if this holds a single integer
    bool isInteger() const { return isInt; }

    // Return the single integer value
    int getInteger() const { return value; }

    // Set this NestedInteger to hold a single integer
    void setInteger(int val) {
        isInt = true;
        value = val;
        list.clear();
    }

    // Add a NestedInteger element to the list
    void add(const NestedInteger &ni) {
        if (isInt) { // convert to list if previously int
            isInt = false;
            list.clear();
        }
        list.push_back(ni);
    }

    // Return the nested list
    const vector<NestedInteger> &getList() const { return list; }
};

// ---------------------------------------------------
// Solution class
// ---------------------------------------------------
class Solution {
public:
    NestedInteger deserialize(string s) {
        // Case 1: If input is just a number
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }

        stack<NestedInteger> st;
        int numStart = 0;
        bool numPending = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '[') {
                st.push(NestedInteger()); // start new list
            }
            else if (c == '-' || isdigit(c)) {
                if (!numPending) {
                    numStart = i;
                    numPending = true;
                }
            }
            else if (c == ',' || c == ']') {
                if (numPending) {
                    int num = stoi(s.substr(numStart, i - numStart));
                    st.top().add(NestedInteger(num));
                    numPending = false;
                }
                if (c == ']') {
                    NestedInteger ni = st.top();
                    st.pop();
                    if (st.empty()) return ni;
                    st.top().add(ni);
                }
            }
        }
        return NestedInteger(); // shouldn't reach here
    }
};

// ---------------------------------------------------
// Helper function to print NestedInteger for testing
// ---------------------------------------------------
void printNestedInteger(const NestedInteger &ni) {
    if (ni.isInteger()) {
        cout << ni.getInteger();
    } else {
        cout << "[";
        const auto &lst = ni.getList();
        for (int i = 0; i < lst.size(); i++) {
            printNestedInteger(lst[i]);
            if (i != lst.size() - 1) cout << ",";
        }
        cout << "]";
    }
}

// ---------------------------------------------------
// Main function
// ---------------------------------------------------
int main() {
    Solution sol;
    string s = "[123,[456,[789]]]";
    NestedInteger result = sol.deserialize(s);

    cout << "Parsed Output: ";
    printNestedInteger(result);
    cout << endl;

    return 0;
}

/*
------------------- DRY RUN -------------------
Input: s = "[123,[456,[789]]]"

Step 1: c='[' → push empty list → stack: [ [] ]
Step 2: read "123" → add to top → stack: [ [123] ]
Step 3: c='[' → push new empty list → stack: [ [123], [] ]
Step 4: read "456" → add to top → stack: [ [123], [456] ]
Step 5: c='[' → push new empty list → stack: [ [123], [456], [] ]
Step 6: read "789" → add to top → stack: [ [123], [456], [789] ]
Step 7: c=']' → pop [789], add to [456] → stack: [ [123], [456, [789]] ]
Step 8: c=']' → pop [456,[789]], add to [123] → stack: [ [123, [456, [789]]] ]
Step 9: c=']' → pop → stack empty → return [123, [456, [789]]]

Output: [123,[456,[789]]]
-----------------------------------------------
*/
