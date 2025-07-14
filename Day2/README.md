# 📘 Day 2 – 15 July 2025 – LeetCode #2 Add Two Numbers

## 🔗 Problem Link:
[https://leetcode.com/problems/add-two-numbers](https://leetcode.com/problems/add-two-numbers)

## 💡 Problem Statement:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each node contains a single digit. Add the two numbers and return the sum as a linked list.

## 🧠 Approach:
- Use a dummy node to build the result list.
- Traverse both linked lists, adding corresponding digits.
- Carry over if the sum ≥ 10.
- Continue until both lists and carry are exhausted.

---

## ✅ Full C++ Code:

```cpp
#include <iostream>
using namespace std;

// Simple structure for a Linked List node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // starting point of result list
        ListNode* temp = dummy; // pointer to build the list
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            temp->next = new ListNode(sum % 10); // store the last digit
            temp = temp->next;
        }

        return dummy->next; // final result starts from next of dummy
    }
};
```

---

## 🧪 Sample Input:
```
l1 = [2,4,3], l2 = [5,6,4]
```

## 🎯 Output:
```
[7,0,8]
```

This represents 342 + 465 = 807

---

### 🔁 Updated on: 15 July 2025
