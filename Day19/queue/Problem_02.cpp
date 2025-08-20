#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int *arr;

public:
    // Constructor
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == size - 1);
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        cout << value << " inserted into Queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << arr[front] << " removed from Queue." << endl;
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front++;
        }
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Display Queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q(5); // Queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();

    q.dequeue();
    q.display();

    return 0;
}

/*
-----------------------------------
🔎 DRY RUN of Main Function
-----------------------------------
Queue size = 5

1) enqueue(10) → Queue: [10]
2) enqueue(20) → Queue: [10, 20]
3) enqueue(30) → Queue: [10, 20, 30]
   display → "10 20 30"
   peek → 10
4) dequeue() → removes 10 → Queue: [20, 30]
   display → "20 30"
5) enqueue(40) → Queue: [20, 30, 40]
6) enqueue(50) → Queue: [20, 30, 40, 50]
7) enqueue(60) → Queue: [20, 30, 40, 50, 60]
   display → "20 30 40 50 60"
8) dequeue() → removes 20 → Queue: [30, 40, 50, 60]
   display → "30 40 50 60"
-----------------------------------
*/
