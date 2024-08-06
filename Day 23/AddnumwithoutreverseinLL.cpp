// Time Complexity: O(m+n)
// Space Complexity: O(m+n)

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
    // Follow up: Could you solve it without reversing the input lists?
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Vectors to store the values from the linked lists
        vector<int> nums1, nums2;

        // Traverse the first linked list and store the values in nums1
        while (l1) {
            nums1.push_back(l1->val);
            l1 = l1->next;
        }

        // Traverse the second linked list and store the values in nums2
        while (l2) {
            nums2.push_back(l2->val);
            l2 = l2->next;
        } 
        
        // Get the sizes of the vectors
        int m = nums1.size(), n = nums2.size();
        int sum = 0, carry = 0;

        // Pointers for the result linked list
        ListNode *head = nullptr, *p = nullptr;

        // Loop through the vectors from the end to the beginning, simulating
        // the addition
        for (int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
            sum = carry; // Start with the carry from the previous step

            // Add the current digit of the first number if available
            if (i >= 0)
                sum += nums1[i];

            // Add the current digit of the second number if available
            if (j >= 0)
                sum += nums2[j];

            carry = sum / 10; // Update carry for the next step

            // Create a new node with the digit value (sum % 10)
            p = new ListNode(sum % 10);

            // Insert the new node at the front of the result list
            p->next = head;
            head = p;
        }

        // Return the head of the resulting linked list
        return head;
    }
};