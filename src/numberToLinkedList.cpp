/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node *head = (struct node *) malloc(sizeof(struct node));
	struct node *temp;
	head -> next = NULL;
	if (N == 0) {
		head -> num = N;
	}
	else {
		if (N < 0) {
			N *= -1;
		}
		while (N > 0) {
			temp = (struct node *) malloc(sizeof(struct node));
			temp -> next = head;
			head -> num = N % 10;
			head = temp;
			N /= 10;
		}
		head = head -> next;
		free(temp);
	}
	return head;
}