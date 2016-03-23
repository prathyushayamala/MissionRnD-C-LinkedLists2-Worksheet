/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	int index;
	struct node *next_node,*prev_node=head;
	if (head == NULL){
		return NULL;
	}
	else{
		if (K <= 0){
			return NULL;
		}
		else{
			int len=0; 
			struct node* temp = head;
			while (temp != NULL){
				temp = temp->next;
				len++;
			}
			if (K > len){
				return head;
			}
			else{
				temp = head;
				index = 0;
				while (temp!=NULL){
					prev_node = temp;
					temp = temp->next;
					index++;
					if (index%K == 0){
						//next_node = temp->next;
						struct node* current = (struct node*)malloc(sizeof(struct node));
						prev_node->next = current;
						current->num =K;
						current->next = temp;
						index = 0;
					}
				}
				return head;
			}
		}
	}
}
