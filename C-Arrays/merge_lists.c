#include <stdlib.h>

// Merges two lists and returns a merged list

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    // Introduce a dummy node to simplify the 
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* current = &dummy;

    // Traverse the two lists simultaneously,
    // adding sorted nodes to merged list

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    // Handle cases of unequal lists
    if (list1 != NULL)
    {
        current->next = list1;
    }

    else if (list2 != NULL)
    {
        current->next = list2;
    }
    return dummy.next; // Skip dummy node

    
}