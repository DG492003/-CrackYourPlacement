// Time Complexity: (O(n))

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
        if (!head)
            return NULL;
        // Initialize the pointer to traverse the list
        ListNode* temp = head;
        while (temp->next) {
            // Check if current node is a duplicate
            // Skip the duplicate node
            if (temp->val == temp->next->val)
                temp->next = temp->next->next;
            // Move to the next node
            else
                temp = temp->next;
        }

        return head;
    }
};