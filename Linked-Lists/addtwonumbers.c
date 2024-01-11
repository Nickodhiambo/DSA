#include <stdlib.h>

// Takes two singly linked lists and computes
// the sum of integers at corresponding positions

// Definition for singly-linked list.
 struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Allocate memory for head pointer and new node instance
    struct ListNode* head =  (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = head;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;
        
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum %= 10;

        // Add values in the resultant linked list
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next = newnode;
        current = current->next;
        current->val = sum;
        current->next = NULL;
    }
    struct ListNode* result = head->next;
    free(head);
    return result;
}