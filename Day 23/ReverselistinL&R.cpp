// time complexity of O(n) and a space complexity of O(1).

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: If the list is empty or left equals right, no changes are
        // needed.
        if (!head || left == right)
            return head;

        // Create a dummy node to handle edge cases where reversal starts from
        // the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize pointers
        ListNode* prev = dummy;
        ListNode* current = head;

        // Move the pointers to the correct starting positions
        for (int i = 1; i < left; ++i) {
            prev = current;
            current = current->next;
        }

        // The `prev` pointer is now just before the `left` position
        // `current` is at the `left` position

        // Start reversing the sublist
        ListNode* tail = current;
        ListNode* next = nullptr;
        ListNode* prevReversed = nullptr;

        for (int i = left; i <= right; ++i) {
            next = current->next;
            current->next = prevReversed;
            prevReversed = current;
            current = next;
        }

        // Reconnect the reversed sublist with the remaining parts
        prev->next = prevReversed;
        tail->next = current;

        // The new head of the list is still `dummy->next`
        ListNode* newHead = dummy->next;

        delete dummy; // Clean up the dummy node
        return newHead;
    }
};