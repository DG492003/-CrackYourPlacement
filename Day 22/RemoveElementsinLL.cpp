// Time complexity : O(n)
// Space complexity : O(1)

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
    ListNode* removeElements(ListNode* head, int val) {
        // if head is null
        if (!head)
            return nullptr;
        // only node with value which is going to delete
        if (!head->next && head->val == val)
            return nullptr;
        // only node with value other than which is going to delete
        if (!head->next && head->val != val)
            return head;
        // if list has only duplicates
        while (head && head->val == val) {
            ListNode* temp1 = head;
            head = head->next;
            temp1->next = NULL;
            delete temp1;
        }

        ListNode* temp = head;
        while (temp && temp->next) {
            ListNode* curr = temp->next;
            if (temp->next->val == val) {
                temp->next = curr->next;
                curr->next = NULL;
                delete curr;
            } else {
                temp = temp->next;
                curr = curr->next;
            }
        }
        return head;
    }
};