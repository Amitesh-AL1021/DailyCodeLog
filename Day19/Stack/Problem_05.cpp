#include <bits/stdc++.h>
using namespace std;

/*
1381. Design a Stack With Increment Operation
We design a custom stack with push, pop, and increment in O(1) time using lazy increment technique.
*/

class CustomStack {
private:
    int maxSize;            // Max allowed stack size
    vector<int> stack;      // Stack elements
    vector<int> inc;        // Pending increments

public:
    // Constructor: initialize maxSize
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    // Push element if stack not full
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
            inc.push_back(0); // No increment initially
        }
    }

    // Pop element and apply pending increment
    int pop() {
        if (stack.empty()) return -1;

        int i = stack.size() - 1;
        if (i > 0) inc[i - 1] += inc[i]; // Propagate increment to next element

        int res = stack.back() + inc[i];
        stack.pop_back();
        inc.pop_back();
        return res;
    }

    // Increment bottom k elements by val
    void increment(int k, int val) {
        if (!stack.empty()) {
            int i = min(k, (int)stack.size()) - 1;
            inc[i] += val; // Mark pending increment
        }
    }
};

int main() {
    // Example usage:
    CustomStack stk(5); // Stack capacity = 5

    stk.push(5);        // stack: [5]
    stk.push(2);        // stack: [5, 2]
    stk.increment(2, 3);// bottom 2 elements +3

    cout << stk.pop() << "\n"; // Expected 5

    stk.push(7);        // stack: [5, 7]
    stk.push(1);        // stack: [5, 7, 1]
    stk.push(8);        // stack: [5, 7, 1, 8]
    stk.increment(3, 1);// bottom 3 elements +1

    cout << stk.pop() << "\n"; // Expected 8
    cout << stk.pop() << "\n"; // Expected 2

    return 0;
}

/*
================= DRY RUN =================

Initial: stack=[], inc=[]

1. push(5)
   stack = [5]
   inc   = [0]

2. push(2)
   stack = [5, 2]
   inc   = [0, 0]

3. increment(2, 3)
   min(2, size=2) = 2
   inc[1] += 3
   stack = [5, 2]
   inc   = [0, 3]

4. pop()
   i = 1
   inc[0] += inc[1] -> inc = [3, 3]
   res = 2 + 3 = 5
   Remove top -> stack = [5], inc = [3]
   Output: 5

5. push(7)
   stack = [5, 7]
   inc   = [3, 0]

6. push(1)
   stack = [5, 7, 1]
   inc   = [3, 0, 0]

7. push(8)
   stack = [5, 7, 1, 8]
   inc   = [3, 0, 0, 0]

8. increment(3, 1)
   min(3, size=4) = 3
   inc[2] += 1
   stack = [5, 7, 1, 8]
   inc   = [3, 0, 1, 0]

9. pop()
   i = 3
   inc[2] += inc[3] (0) -> inc = [3, 0, 1, 0]
   res = 8 + 0 = 8
   Remove top -> stack = [5, 7, 1], inc = [3, 0, 1]
   Output: 8

10. pop()
    i = 2
    inc[1] += inc[2] (1) -> inc = [3, 1, 1]
    res = 1 + 1 = 2
    Remove top -> stack = [5, 7], inc = [3, 1]
    Output: 2

Final Output:
5
8
2
==========================================
*/
