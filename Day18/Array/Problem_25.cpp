#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0); // Dummy head
        ListNode* curr = head;

        while (curr) {
            ListNode* prev = dummy;
            ListNode* nextNode = curr->next;

            // Find the right place to insert
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy->next;
    }
};

// ---------- Helper Functions for Testing ----------
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(vector<int> arr) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    for (int x : arr) {
        temp->next = new ListNode(x);
        temp = temp->next;
    }
    return dummy->next;
}

int main() {
    Solution sol;

    // Example Input: [4, 2, 1, 3]
    vector<int> arr = {4, 2, 1, 3};
    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    head = sol.insertionSortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
