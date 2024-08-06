// Time complexity: O(N)
// Space complexity: O(1)


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
    ListNode* partition(ListNode* head, int x) {
        // If the list is empty or has only one node, return the head itself.
        if (!head || !head->next)
            return head;

        // Create two dummy nodes for the two partitions:
        // one for nodes greater than or equal to x and one for nodes smaller
        // than x.
        ListNode* greater = new ListNode(-1);
        ListNode* smaller = new ListNode(-1);

        // Create pointers to traverse and build the two partitions.
        ListNode* dumg = greater;
        ListNode* dums = smaller;

        // Traverse the original list.
        while (head) {
            // If the current node's value is greater than or equal to x,
            // append it to the 'greater' list.
            if (head->val >= x) {
                dumg->next = head;
                dumg = head;
            } else {
                // Otherwise, append it to the 'smaller' list.
                dums->next = head;
                dums = head;
            }

            // Move to the next node in the original list.
            head = head->next;
        }

        // Terminate the 'greater' list.
        dumg->next = NULL;

        // Link the end of the 'smaller' list to the beginning of the 'greater'
        // list.
        dums->next = greater->next;

        // Return the beginning of the 'smaller' list, skipping the dummy node.
        return smaller->next;
    }
};