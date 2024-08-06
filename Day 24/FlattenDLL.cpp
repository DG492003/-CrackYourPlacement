// TC - O(n)
// Sc - O(1)


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // Iterate through each node in the list
        for (Node* h = head; h; h = h->next) {
            // Check if the current node has a child
            if (h->child) {
                // Save the next node (which is connected after the child list)
                Node* next = h->next;

                // Connect the current node to its child
                h->next = h->child;
                // Set the previous pointer of the child to the current node
                h->next->prev = h;
                // Remove the reference to the child list
                h->child = NULL;

                // Traverse to the end of the child list
                Node* p = h->next;
                // Move p to the last node of the child list
                while (p->next)
                    p = p->next;

                // Connect last node of the child list to the saved nextnode
                p->next = next;
                // If the saved next node exists, set its prev pointer to the
                // last node of the child list
                if (next)
                    next->prev = p;
            }
        }
        // Return the modified list head
        return head;
    }
};