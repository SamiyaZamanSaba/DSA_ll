#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* midNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* mergeList(ListNode* a, ListNode* b) {
    ListNode* temp = new ListNode(0);
    ListNode* curr = temp;

    while (a && b) {
        if (a->val < b->val) {
            curr->next = a;
            a = a->next;
        } else {
            curr->next = b;
            b = b->next;
        }
        curr = curr->next;
    }

    if (a) curr->next = a;
    if (b) curr->next = b;

    return temp->next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* mid = midNode(head);
    ListNode* right = mid->next;
    mid->next = NULL;

    ListNode* left = sortList(head);
    right = sortList(right);

    return mergeList(left, right);
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    head = sortList(head);

    printList(head);

    return 0;
}
