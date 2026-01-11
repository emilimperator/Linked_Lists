Linked List in C (Practice Project)
A small C project that implements common singly linked list operations using pointers and dynamic memory (malloc / free). Made for learning data structures and pointer manipulation.
Features
This project includes functions for:
	•	Create a linked list from an array
	•	Display the list
	•	Count number of nodes
	•	Sum of all values
	•	Max / Min value
	•	Linear Search (returns index)
	•	Insert at a given index
	•	Insert into sorted list
	•	Append to the end
	•	Delete at a given index
	•	Check if sorted
	•	Remove duplicates (for sorted lists)
	•	Reverse (2 methods)
	◦	Method 1: reverse by copying values into an array
	◦	Method 2: reverse by changing links (pointer reversal)
	•	Concatenating (Copy): creates a new list that contains list1 followed by list2
	•	Merging (Copy): merges two sorted lists into a new sorted list
	•	Loop detection using Floyd’s cycle algorithm (slow/fast pointers)
	•	Free_List to free memory safely
Note: Merging() and Concatenating() are implemented as deep-copy functions (they allocate new nodes). This makes it safe to free first, second, merged, and mixed separately.
Project Goal
This repo is mainly for practicing:
	•	pointers and struct usage
	•	dynamic memory allocation (malloc / free)
	•	linked list algorithms (reverse, merge, duplicates, cycle detection)

Made by Emil
