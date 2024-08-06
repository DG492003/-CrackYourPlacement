// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // If the list is empty or has only one node, return the list as is.
        if (!head || !head->next)
            return head;

        // Create a dummy node that points to the head of the list.
        // This helps handle edge cases such as all nodes being duplicates.
        ListNode* dummy = new ListNode(0, head);

        // 'prev' is a pointer to the node before the current sequence of
        // potential duplicates.
        ListNode* prev = dummy;

        // 'curr' is the pointer used to traverse the list.
        ListNode* curr = head;

        while (curr) {
            // Move 'curr' forward as long as the next node has the same value.
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            }

            // If 'prev' still points to the node before 'curr',
            // it means no duplicates were found in this sequence.
            // Otherwise, duplicates were found, and we should skip them.
            if (prev->next != curr) {
                // Skip all duplicates by pointing 'prev' to the node after
                // 'curr'.
                prev->next = curr->next;
            } else {
                // Move 'prev' forward if no duplicates were found.
                prev = prev->next;
            }

            // Move 'curr' forward to the next node.
            curr = curr->next;
        }

        // Return the modified list, which is pointed to by 'dummy->next'.
        return dummy->next;
    }
};
