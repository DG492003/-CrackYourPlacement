// time complexity -> O(n + m)

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        
        // Initialize variables to store the numerical values of the two linked lists
        long long num1 = 0, num2 = 0;
        long long mod = 1000000007;
        
        // Temporary pointers to traverse the linked lists
        Node* temp1 = first;
        Node* temp2 = second;
    
        // Traverse the first linked list to convert it into a numerical value
        while (temp1) {
            // num1 is multiplied by 10 to shift digits left and then add the current node's value
            // Use modulo operation to keep the number manageable and prevent overflow
            num1 = (num1 * 10) % mod + (temp1->data) % mod;
            // Move to the next node in the list
            temp1 = temp1->next;
        }
    
        // Traverse the second linked list to convert it into a numerical value
        while (temp2) {
            // num2 is multiplied by 10 to shift digits left and then add the current node's value
            // Use modulo operation to keep the number manageable and prevent overflow
            num2 = (num2 * 10) % mod + (temp2->data) % mod;
            // Move to the next node in the list
            temp2 = temp2->next;
        }
    
        // Calculate the product of the two numbers
        // Use modulo operation to prevent overflow
        long long ans = (num1 * num2) % mod;
        
        // Return the result of the multiplication, again using modulo to ensure it is within limits
        return ans % mod;
    }
};