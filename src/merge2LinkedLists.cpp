/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *temp1 = head1,*temp2,*prev_node=head1;
	int temp;
	if ((head1 == NULL)&&(head2 == NULL)){
		return NULL;
	}
	else{
		if (head1 == NULL){
			return head2;
		}
		else{
			if (head2 == NULL){
				return head1;
			}
			else{
				while (temp1 != NULL){
					prev_node = temp1;
					temp1 = temp1->next;
				}
				prev_node->next = head2;
				temp1 = head1;
				while (temp1 != NULL){
					temp2 = temp1->next;
					while (temp2 != NULL){
						if (temp1->num > temp2->num){
							temp = temp1->num;
							temp1->num = temp2->num;
							temp2->num = temp;
						}
						temp2 = temp2->next;
					}
					temp1 = temp1->next;
				}
				return head1;
			}
		}
	}
}
