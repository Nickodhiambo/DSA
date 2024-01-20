#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* current = head;

    while(current)
    {
        int duplicate = 0;

        while (current->next && current->val == current->next->val) {
            // Removes the second duplicate node
            duplicate = 1;
            struct ListNode* temp = current->next;
            current->next = temp->next;
            free(temp);
        }

        if (duplicate) {
            // Removes the current duplicate node
            prev->next = current->next;
            free(current);
        }
        else {
                prev = prev->next; // Move to the next node if no duplicates were found
            }
        current = prev->next;
    }
    return dummy.next;
}