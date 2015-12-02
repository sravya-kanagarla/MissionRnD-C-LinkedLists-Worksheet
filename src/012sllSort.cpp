/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node * insert(int count, struct node *temp, int n) {
	while (count) {
		temp->data = n;
		temp = temp->next;
		count--;
	}
	return temp;
}

void sll_012_sort(struct node *head){
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	struct node *temp = head;
	while (temp != NULL) {
		if (temp->data == 0)
			count0++;
		else if (temp->data == 1)
			count1++;
		else
			count2++;
		temp = temp->next;
	}
	temp = head;
	temp = insert(count0, temp, 0);
	temp = insert(count1, temp, 1);
	temp = insert(count2, temp, 2);
}