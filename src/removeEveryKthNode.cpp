/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 1) {
		return NULL;
	}
	int i;
	struct node *temp = head;
	struct node *temp1;
	while (temp != NULL) {
		for (i = K - 1; i > 0 && temp != NULL; i--) {
			temp1 = temp;
			temp = temp->next;
		}
		if (temp != NULL) 
			temp1->next = temp->next;
		delete temp;
		temp = temp1 -> next;
	}
	return head;
}