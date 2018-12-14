#pragma once
#include<stdio.h> 
#include<stdlib.h> 

/* Link list Nodes */
struct Nodes
{
	int data;
	struct Nodes* next;
};

/* function prototypes */
struct Nodes* SortedMerge(struct Nodes* a, struct Nodes* b);
void FrontBackSplit(struct Nodes* source,
	struct Nodes** frontRef, struct Nodes** backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct Nodes** headRef)
{
	struct Nodes* head = *headRef;
	struct Nodes* a;
	struct Nodes* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}


struct Nodes* SortedMerge(struct Nodes* a, struct Nodes* b)
{
	struct Nodes* result = NULL;

	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}
void FrontBackSplit(struct Nodes* source,
	struct Nodes** frontRef, struct Nodes** backRef)
{
	struct Nodes* fast;
	struct Nodes* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two Nodess, and advance 'slow' one Nodes */
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

/* Function to print Nodess in a given linked list */
void printList(struct Nodes *Nodes)
{
	while (Nodes != NULL)
	{
		printf("%d ", Nodes->data);
		Nodes = Nodes->next;
	}
}

/* Function to insert a Nodes at the beginging of the linked list */
void push(struct Nodes** head_ref, int new_data)
{
	/* allocate Nodes */
	struct Nodes* new_Nodes =
		(struct Nodes*) malloc(sizeof(struct Nodes));

	/* put in the data */
	new_Nodes->data = new_data;

	/* link the old list off the new Nodes */
	new_Nodes->next = (*head_ref);

	/* move the head to point to the new Nodes */
	(*head_ref) = new_Nodes;
}

/* Drier program to test above functions*/