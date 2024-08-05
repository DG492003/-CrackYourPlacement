// Time Complexity: O(N), where N is the number of nodes in the linked list.
// Auxiliary Space: O(1)

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here
        
        if (!head || !(head->next)) 
            return head; 
            
        // Create three dummy nodes to point to beginning of 
        // three linked lists. These dummy nodes are created to 
        // avoid null checks. 
        Node* zeroD = new Node(0); 
        Node* oneD = new Node(0); 
        Node* twoD = new Node(0);
        // Initialize current pointers for three lists 
        Node *zero = zeroD, *one = oneD, *two = twoD; 
        
        // Traverse list 
        Node* curr = head; 
        while (curr) { 
            if (curr->data == 0) { 
                  // If the data of current node is 0, 
                  // append it to pointer zero and update zero
                zero->next = curr; 
                zero = zero->next; 
            } 
            else if (curr->data == 1) { 
                  // If the data of current node is 1, 
                  // append it to pointer one and update one
                one->next = curr; 
                one = one->next; 
            } 
            else { 
                  // If the data of current node is 2, 
                  // append it to pointer two and update two
                two->next = curr; 
                two = two->next; 
            } 
            curr = curr->next; 
        } 
        
        // Combine the three lists
        zero->next = (oneD->next) ? (oneD->next) : (twoD->next); 
        one->next = twoD->next; 
        two->next = NULL; 
          
        // Updated head 
        head = zeroD->next; 
    
        // Delete dummy nodes 
        delete zeroD; 
        delete oneD; 
        delete twoD; 
    
        return head; 
    }
};