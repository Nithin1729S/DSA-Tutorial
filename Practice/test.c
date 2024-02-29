struct Node* partition(struct Node* first, struct Node* last) 
{ 
	// Get the first node of the given linked list as the pivot
	struct Node* pivot = first;
	
	// 'front' is used to traverse the linked list from 'first' to 'last'
	struct Node* front = first;
	
	int temp = 0;  // Temporary variable for swapping values

	while (front != NULL && front != last) { 
		if (front->data < last->data) { 
			// If the current element is less than the pivot (last element),
			// swap the current element with the element pointed to by 'first'
			
			// Swap node values
			temp = first->data;
			first->data = front->data;
			front->data = temp;
			
			// Move 'first' to the next node
			first = first->next; 
		} 
		// Move 'front' to the next node
		front = front->next; 
	} 

	// At this point, all elements less than the pivot have been moved to the left side,
	// and all elements greater than or equal to the pivot are on the right side.
	
	// Finally, swap the pivot (last element) with the element pointed to by 'first'
	temp = first->data;
	first->data = last->data;
	last->data = temp;

	// Return 'pivot,' which is the new position of the pivot element after rearrangement.
	return pivot; 
}
