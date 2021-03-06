/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

/*struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node *temp = head;
	struct node *temp1;
	int t;
	while (temp != NULL) {
		temp1 = temp->next;
		while (temp1 != NULL) {
			if (temp -> num > temp1 -> num) {
				t = temp->num;
				temp->num = temp1->num;
				temp1->num = t;
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
	return head;
}*/

struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node *temp = head -> next;
	struct node *temp1;
	struct node *temp2;
	struct node *temp3;
	head->next = NULL;
	while (temp != NULL) {
		temp1 = head;
		while (temp1 -> next != NULL && temp1->num <= temp->num) {
			temp3 = temp1;
			temp1 = temp1->next;
		}
		if (temp1->num > temp->num) {
			temp2 = temp;
			temp = temp->next;
			temp2->next = temp1;
			if (temp1 == head) {
				head = temp2;
			}
			else {
				temp3->next = temp2;
			}
		} else {
			temp1->next = temp;
			temp = temp->next;
			temp1 = temp1->next;
			temp1->next = NULL;
		}
	}
	return head;
}