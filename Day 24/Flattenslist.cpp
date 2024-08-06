/*
Time Complexity: O( N*(2M) ) ~ O(2 N*M)
Space complexity: O(1)

Step 1: Establish Base Case Conditions Check if the base case conditions are met, return the head if it is null or has no next pointer to head as there’s no further flattening or merging required.
Step 2: Recursively Merge the List:
    Initiate the recursive flattening process by calling `flattenLinkedList` on the next node (`head -> next`).
    The result of this recursive call is the head of the flattened and merged linked list.
Step 3: Merge Operations:
    Inside the recursive call, call the merge function which takes care of the merging of these two lists based on their data values.
    Read more about merging two linked lists here.
    The merged list is updated in the head, which is then returned as the result of the flattening process.*/

class Solution {
  private:
    // Merges two linked lists in a particular
    // order based on the data value
    Node* merge(Node* list1, Node* list2){
        // Create a dummy node as a
        // placeholder for the result
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
    
        // Merge the lists based on data values
        while(list1 != NULL && list2 != NULL){
            if(list1->data < list2->data){
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            }
            else{
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = NULL;
        }
    
        // Connect the remaining
        // elements if any
        if(list1)
            res->bottom = list1;
        else
            res->bottom = list2;
    
        // Break the last node's
        // link to prevent cycles
        if(dummyNode->bottom)
            dummyNode->bottom->next = NULL;
    
        return dummyNode->bottom;
        
        
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        
        // If head is null or there 
        // is no next node, return root
        if(root == NULL || root->next == NULL)
            return root;
            
        // Recursively flatten the
        // rest of the linked list
        
        // by this we traverse till very end of the list
        Node* mergedroot = flatten(root->next);
        // then we merge last 2 nodes with bottom pointer
        root = merge(root, mergedroot);
        return root;
    }
};