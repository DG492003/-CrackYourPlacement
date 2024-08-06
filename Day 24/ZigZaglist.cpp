/*
Time Complexity: O(n). 
Auxiliary Space: O(1). 

Approach ->
The zigZagList function operates by traversing the linked list and ensuring that each pair of consecutive nodes is arranged in alternating order (less than or greater than), based on a flag that is toggled on each iteration:
    Flag = true: The current node should be less than or equal to the next node.
    Flag = false: The current node should be greater than or equal to the next node.

If the condition indicated by the flag is not met, the data values of the current node and the next node are swapped. After processing each pair, the flag is toggled.


// C++ program to arrange linked list in zigzag fashion 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list Node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

// This function distributes the Node in zigzag fashion 
void zigZagList(Node* head) 
{ 
	// If flag is true, then next node should be greater in 
	// the desired output. 
	bool flag = true; 

	// Traverse linked list starting from head. 
	Node* current = head; 
	while (current->next != NULL) { 
		if (flag) /* "<" relation expected */
		{ 
			// If we have a situation like A > B > C where 
			// A, B and C are consecutive Nodes in list we 
			// get A > B < C by swapping B and C 
			if (current->data > current->next->data) 
				swap(current->data, current->next->data); 
		} 
		else /* ">" relation expected */
		{ 
			// If we have a situation like A < B < C where 
			// A, B and C are consecutive Nodes in list we 
			// get A < C > B by swapping B and C 
			if (current->data < current->next->data) 
				swap(current->data, current->next->data); 
		} 

		current = current->next; 
		flag = !flag; /* flip flag for reverse checking */
	} 
} 
