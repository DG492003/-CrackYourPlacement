// Time Complexity: O(3N)
// Space Complexity : O(N)


// Step 1: Traverse the original node and create a copy of each node and insert it in between the original node and the next node.

// Step 2: Traverse this modified list and for each original node that has a random pointer, set the copied node’s random pointer to the corresponding copies random node. If the original node’s random pointer is full, set the copied node’s random pointe to null as well.

// Step 3: RecursionTraverse the modified list again and extract the copied nodes by breaking the links between the original nodes and the copied nodes. Revert the original list to its initial state by fixing the next pointers.

// Step 4: Return the head of the deep copy obtained after extracting the copied nodes from the modified list.


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    // Function to insert a copy of each
    // node in between the original nodes
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextElement = temp->next;
            // Create a new node with the same val
            Node* copy = new Node(temp->val);

            // Point the copy's next to
            // the original node's next
            copy->next = nextElement;

            // Point the original
            // node's next to the copy
            temp->next = copy;

            // Move to the next original node
            temp = nextElement;
        }
    }

    // Function to connect random
    // pointers of the copied nodes
    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            // Access the copied node
            Node* copyNode = temp->next;

            // If the original node
            // has a random pointer
            if (temp->random) {
                // Point the copied node's random to the
                // corresponding copied random node
                copyNode->random = temp->random->next;
            } else {
                // Set the copied node's random to
                // null if the original random is null
                copyNode->random = NULL;
            }

            // Move to the next original node
            temp = temp->next->next;
        }
    }

    // Function to retrieve the
    // deep copy of the linked list
    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        // Create a dummy node
        Node* dummyNode = new Node(-1);
        // Initialize a result pointer
        Node* res = dummyNode;

        while (temp != NULL) {
            // Creating a new List by
            // pointing to copied nodes
            res->next = temp->next;
            res = res->next;

            // Disconnect and revert back to the
            // initial state of the original linked list
            temp->next = temp->next->next;
            temp = temp->next;
        }

        // Return the deep copy of the
        // list starting from the dummy node
        return dummyNode->next;
    }

public:
    Node* copyRandomList(Node* head) {
        // If the original list
        // is empty, return null
        if (!head)
            return nullptr;

        // Step 1: Insert copy of
        // nodes in between
        insertCopyInBetween(head);
        // Step 2: Connect random
        // pointers of copied nodes
        connectRandomPointers(head);
        // Step 3: Retrieve the deep
        // copy of the linked list
        return getDeepCopyList(head);
    }
};