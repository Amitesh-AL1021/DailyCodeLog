#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a stack of integers
    stack<int> st;

    // Push elements into the stack
    st.push(10); // stack: [10]
    st.push(20); // stack: [10, 20]
    st.push(30); // stack: [10, 20, 30]

    // Display top element
    cout << "Top element: " << st.top() << endl;

    // Pop one element
    st.pop(); // removes 30 → stack: [10, 20]

    // Display top element again
    cout << "Top after pop: " << st.top() << endl;

    // Check if stack is empty
    if (st.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack has elements" << endl;
    }

    return 0;
}

/*
---------------- DRY RUN ----------------

Initial stack: (empty)

1) st.push(10)
   stack = [10]
   Top = 10

2) st.push(20)
   stack = [10, 20]
   Top = 20

3) st.push(30)
   stack = [10, 20, 30]
   Top = 30
   Output: "Top element: 30"

4) st.pop()
   stack = [10, 20]
   Top = 20
   Output: "Top after pop: 20"

5) st.empty() → false
   Output: "Stack has elements"

------------------------------------------
Expected Output:
Top element: 30
Top after pop: 20
Stack has elements
------------------------------------------
*/
