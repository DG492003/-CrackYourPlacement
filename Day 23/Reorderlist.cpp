// Time Complexity:
//     Finding the Middle: O(n) 
//     Reversing the List: O(n/2)=O(n) because we reverse half of the list.
//     Merging the Lists: O(n) since we process each node exactly once.
//     Overall time complexity: O(n).
// space complexity: O(1).

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
    // Function to find the middle of the linked list
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // `slow` is now at the middle
    }

    // Function to reverse the linked list
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forw = NULL;
        // Iterate through the list and reverse the pointers
        while (curr) {
            forw = curr->next; // Store next node
            curr->next = prev; // Reverse current node's pointer
            prev = curr;       // Move `prev` and `curr` one step forward
            curr = forw;
        }
        return prev; // `prev` is the new head of the reversed list
    }

public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        ListNode* mid = middle(head);     // Find the middle of the list
        ListNode* k = reverse(mid->next); // Reverse the second half of the list
        mid->next = NULL;                 // Break the list into two halves

        ListNode* c1 = head; // Pointer for the first half
        ListNode* c2 = k;    // Pointer for the reversed second half
        ListNode* f1 = NULL; // Temp pointer for the next node in first half
        ListNode* f2 = NULL; // Temp pointer for the next node in second half

        // Merge the two halves alternately
        while (c1 != NULL && c2 != NULL) {
            f1 = c1->next; // Store next node of the first half
            f2 = c2->next; // Store next node of the second half
            
            // Link curr node of the first half to curr node of second half
            c1->next = c2;
            // Link curr node of the second half to the next node of
            // first half
            c2->next = f1;

            c1 = f1; // Move to the next node in the first half
            c2 = f2; // Move to the next node in the second half
        }
    }
};