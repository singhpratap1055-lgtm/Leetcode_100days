/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
    
    // If list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Traverse the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps
        
        // If they meet, cycle exists
        if (slow == fast) {
            return true;
        }
    }
    
    // No cycle found
    return false;
}