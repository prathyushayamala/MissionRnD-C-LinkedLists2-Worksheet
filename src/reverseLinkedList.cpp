/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL){
		return NULL;
	}
	else{
		if (head->next == NULL){
			return head;
		}
		else{
			struct node* previous_node = NULL;
			struct node* temp_node = head;
			struct node* next_node = NULL;
			while (temp_node != NULL){
				next_node = temp_node->next;
				temp_node->next = previous_node;
				previous_node = temp_node;
				temp_node = next_node;
			}
			head = previous_node;
			return head;
		}
	}
}
