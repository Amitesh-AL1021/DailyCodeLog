#include <iostream>
#include <stack>
using namespace std;

// Queue class using two stacks
class MyQueue {
public:
    stack<int> s1, s2;

    // Push element x to the back of queue
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from the front of queue and returns it
    int pop() {
        int val = peek();  // first get front element
        s2.pop();          // remove it from s2
        return val;
    }

    // Get the front element
    int peek() {
        // If s2 is empty, move all elements from s1 → s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Return whether the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    MyQueue q;

    cout << "Pushing elements 1, 2, 3 into queue...\n";
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // should print 1

    cout << "Popping element: " << q.pop() << endl; // should remove 1
    cout << "Front element after pop: " << q.peek() << endl; // should print 2

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    q.pop(); // removes 2
    q.pop(); // removes 3

    cout << "Is queue empty now? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
