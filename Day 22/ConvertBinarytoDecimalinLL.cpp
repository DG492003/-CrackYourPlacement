// Tc - O(n)
// Sc - O(1)

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
    int getDecimalValue(ListNode* head) {
        // get the length of the list
        ListNode* temp = head;
        int size = 0;
        while (temp) {
            size++;
            temp = temp->next;
        }
        // convert size according to the 0-based indexing
        size -= 1;
        // reset temp to head
        temp = head;

        int value = 0;
        while (temp) {
            if (temp->val == 1)
                value += pow(2, size);
            size--;
            temp = temp->next;
        }
        return value;
    }
};