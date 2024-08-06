// Time Complexity: O(n)
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes to reverse
        ListNode* curr = head;
        int count = 0;

        // Traverse the list to count k nodes
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        // If there are fewer than k nodes left, no reversal is needed
        if (count < k)
            return head;

        // Step 2: Reverse the first k nodes
        // Will eventually be the new head of the reversed segment
        ListNode* prev = NULL;
        ListNode* next = NULL; // Used to temporarily store the next node
        curr = head;           // Reset curr to the start of the list
        count = 0;

        // Reverse the k nodes
        while (curr && count < k) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the current node's next pointer
            prev = curr;       // Move prev to the current node
            curr = next;       // Move curr to the next node
            count++;
        }

        // Step 3: Recursively reverse the rest of the list and connect it to
        // the reversed part
        if (next)
            head->next = reverseKGroup(next, k);

        // Return the new head of the reversed segment
        return prev;
    }
};