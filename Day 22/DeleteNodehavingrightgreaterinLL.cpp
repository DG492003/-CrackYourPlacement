// Time Complexity : O(n)
// Space Complexity : O(n) due to recursive stack

// if (temp->data >= connect->data)
//     If the data of the current node (temp->data) is greater than or equal to the data of the node returned by the recursive call (connect->data):
//         temp->next = connect;
//         Connect the current node to the processed list.
//         return temp;
//         Return the current node as the head of the new processed list.
// return connect;
//     If the data of the current node is less than the data of the node returned by the recursive call, we skip the current node and return the node returned by the recursive call (connect). This effectively removes the current node from the list.

class Solution
{
    public:
    Node *compute(Node *temp){
        // your code goes here
        
        // Base case: If the node is the last node, return it
        if (temp->next == nullptr)
            return temp;
        // Recursively compute the next part of the list
        Node* connect = compute(temp->next);
                
        // If the current node's data is greater than or equal to the next node's data
        // it means we keep the current node and connect it to the rest of the processed list
        if (temp->data >= connect->data) {
            temp->next = connect;
            return temp;
        }
        
        // If the current node's data is less than the next node's data,
        // we skip the current node and return the connect node which will be linked to the previous nodes
        return connect;
    }
    
};