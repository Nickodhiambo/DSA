
 // Definition for singly-linked list.
 struct ListNode {
      int val;
      struct ListNode *next;
  };

// Swaps adjacent nodes of a list

struct ListNode* swapPairs(struct ListNode* head) {
    // Create a dummy node to simplify the code
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = &dummy;

    // Iterate through the list and swap every two adjacent nodes
    while (current->next != NULL && current->next->next != NULL) {
        struct ListNode* first = current->next;
        struct ListNode* second = current->next->next;

        // Swap nodes
        current->next = second;
        first->next = second->next;
        second->next = first;

        // Move to the next pair of nodes
        current = current->next->next;
    }

    return dummy.next;
}