// Time Complexity:  O(n+m)
// Auxiliary Space: O(n+m)


class Solution {
private:
    // function to get the size of list
    int len(Node* node) {
        Node* curr{node};
        int l{0};
        while(curr){
            l++;
            curr = curr->next;
        }
        return l;
    }
    // function to remove leading zeroes
    Node* stripLeadingZeroes(Node* head){
        while(head && head->next && head->data == 0){
            Node* trash{head};
            head = head->next;
            delete trash;   // could make it lil fast by removing this line 
                            // but will do memory leak
        }
        return head;
    }
    // function to reverse the list
    Node* reverse(Node* node) {
        if(!node || !node->next) return node;
        
        Node* prev{nullptr};
        Node* curr{node};
        Node* next{node->next};
        
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next) next = next->next;
        }
        
        return prev;
    }
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        
        // strip leading zeroes
        head1 = stripLeadingZeroes(head1);
        head2 = stripLeadingZeroes(head2);
        
        // get the sizes of lists
        int l1 = len(head1);
        int l2 = len(head2);
        
        // maintain head1 > head2 numerically   
        // find which is greater
        // ans swap accordingly
        // straight forward
        if(l2 > l1) swap(head1, head2);
        // need to check numerically
        if(l1 == l2){
            Node* c1{head1};
            Node* c2{head2};
            while(c1 && c2){
                if(c1->data > c2->data) break;
                if(c1->data < c2->data){
                    swap(head1, head2);
                    break;
                }
                c1 = c1->next;
                c2 = c2->next;
            }
        }
        
        // actual subtraction
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        // Initialize pointers for traversal
        Node* curr1 = head1;
        Node* curr2 = head2;
        int borrow = 0;
        
        // Perform the subtraction
        while (curr1 && curr2) {
            int a = curr1->data;
            int b = curr2->data;
            // If a with borrow is less than b, we need to borrow
            if ((a + borrow) < b) {
                curr1->data = a + 10 + borrow - b;  // Borrowing adjustment
                if (!borrow) borrow = -1;           // Set borrow flag
            } else {
                curr1->data = a + borrow - b;       // Simple subtraction
                borrow = 0;                         // Reset borrow
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        // If there's still a borrow, handle it in the remaining part of head1
        while (borrow && curr1) {
            int a = curr1->data;
            if ((borrow + a) < 0)
                curr1->data = a + 10 + borrow;  // Borrowing adjustment
            else {
                curr1->data = a + borrow;
                borrow = 0;                     // Reset borrow
            }
            curr1 = curr1->next;
        }
        
        // Reverse the result list back to the correct order and strip leading zeros
        return stripLeadingZeroes(reverse(head1));
        return NULL;
    }
};