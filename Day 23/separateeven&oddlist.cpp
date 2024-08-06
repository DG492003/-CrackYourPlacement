// Time Complexity: O(n), As we are only traversing linearly through the list.
// Auxiliary Space: O(1)

class Solution {
  public:
    Node* divide(Node* head) {
        // creating Heads of Odd and Even LinkedLists
        Node *oddHead = new Node(-1), *oddTail = oddHead;
        Node *evenHead = new Node(-1), *evenTail = evenHead;
        Node *curr = head, *temp;
        
        while (curr){
            // Breaking the Link of the curr Node.
            temp = curr;
            curr = curr->next;
            temp->next = nullptr;
    
            // If odd Node,append to odd LinkedList
            if (temp->data & 1){
                oddTail->next = temp;
                oddTail = temp;
            }
            // If even Node,append to even LinkedList
            else{
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        
        evenTail->next = oddHead->next; 
        // Appending Odd LinkedList at end of EvenLinkedList
        return evenHead->next;
    }
};