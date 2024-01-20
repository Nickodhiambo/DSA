/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || k == 0)
    {
        return head;
    }

    // Step 1: Find the length of linked list
    struct ListNode *current = head;
    int length = 1;
    while(current->next != NULL)
    {
        current = current->next;
        length++;
    }

    // Step 2: Find effective k to handle instances where
    // k is greater than list length
    // This is necessary to avoid duplicated rotations
    k = k % length;

    // Step 3: Check if rotation is necessary with effective k
    if (k == 0)
    {
        return head;
    }

    // Step 4: Move the pointer to the (length - k)th node, the point of rotation
    // The nodes after this node are rotated
    current = head;
    for (int i = 1; i < length - k; i++)
    {
        current = current->next;
    }

    // Update pointers to rotate the list
    struct ListNode *newHead = current->next;
    current->next = NULL; // Break the original list
    current = newHead;

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = head;
    return newHead;
}