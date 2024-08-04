// Time Complexity: O(max(m,n)).
// Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.

// Psuedocode:
//     Create a dummy node which is the head of new linked list.
//     Create a node temp, initialise it with dummy.
//     Initialize carry to 0.
//     Loop through lists l1 and l2 until you reach both ends, and until carry is present.
//         Set sum=l1.val+ l2.val + carry.
//         Update carry=sum/10.
//         Create a new node with the digit value of (sum%10) and set it to temp node's next, then advance temp node to next.
//         Advance both l1 and l2.
// Return dummy's next node.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while ((l1 != NULL || l2 != NULL) || carry) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};