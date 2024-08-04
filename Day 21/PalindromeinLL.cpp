// Time Complexity: O (2* N) The algorithm traverses the linked list twice, dividing it into halves. During the first traversal, it reverses one-half of the list, and during the second traversal, it compares the elements of both halves. As each traversal covers N/2 elements, the time complexity is calculated as O(N/2 + N/2 + N/2 + N/2), which simplifies to O(2N), ultimately representing O(N). 

// Space Complexity: O(1) The approach uses a constant amount of additional space regardless of the size of the input linked list. It doesn't allocate any new data structures that depend on the input size, resulting in a space complexity of O(1).

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
private:
    ListNode* reverseList(ListNode* head) {
        // If the linked list is empty or has only one node,
        // return the head as it is already reversed.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Reverse the linked list starting
        // from the second node (head->next).
        ListNode* newHead = reverseList(head->next);

        // Save a reference to the node following
        // the current 'head' node.
        ListNode* front = head->next;

        // Make the 'front' node point to the current
        // 'head' node in the reversed order.
        front->next = head;

        // Break the link from the current 'head' node
        // to the 'front' node to avoid cycles.
        head->next = NULL;

        // Return the 'newHead,' which is the new
        // head of the reversed linked list.
        return newHead;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        // Initialize two pointers, slow and fast,
        // to find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the linked list to find the
        // middle using slow and fast pointers
        while (fast->next != NULL && fast->next->next != NULL) {
            // Move slow pointer one step at a time
            slow = slow->next;
            // Move fast pointer two steps at a time
            fast = fast->next->next;
        }

        // Reverse the second half of the
        // linked list starting from the middle
        ListNode* newHead = reverseList(slow->next);

        // Pointer to the first half
        ListNode* first = head;
        // Pointer to the reversed second half
        ListNode* second = newHead;

        while (second != NULL) {
            // Compare data values of
            // nodes from both halves

            // If values do not match,
            // the list is not a palindrome
            if (first->val != second->val) {
                // Reverse the second half
                // back to its original state
                reverseList(newHead);
                // Not a palindrome
                return false;
            }

            // Move the first pointer
            first = first->next;
            // Move the second pointer
            second = second->next;
        }
        // Reverse the second half
        // back to its original state
        reverseList(newHead);
        // The linked list is a palindrome
        return true;
    }
};