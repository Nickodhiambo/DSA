// Definition for singly-linked list.
 struct ListNode {
      int val;
      struct ListNode *next;
 };

// Reverses groups of nodes containing k nodes in a list

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    // Check if there are at least k nodes remaining
    struct ListNode* current = head;
    int count = 0;
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }

    // If there are fewer than k nodes, return the original list
    if (count < k) {
        return head;
    }

    // Reverse the first k nodes in the current group
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    current = head;
    count = 0;
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursively reverse the next group
    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    // 'prev' is the new head of the reversed group
    return prev;
}