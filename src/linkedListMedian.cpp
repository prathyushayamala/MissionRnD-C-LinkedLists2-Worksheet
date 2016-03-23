/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int len = 0, result,index;
	struct node *temp = head;
	if (head == NULL){
		return -1;
	}
	else{
		while (temp != NULL){
			temp = temp->next;
			len++;
		}
		temp = head;
		if (len % 2 != 0){
			index = len / 2;
			len = 0;
			while (len < index){
				temp = temp->next;
				len++;
			}
			result = temp->num;
			return result;
		}
		else{
			index = len / 2;
			result = 0;
			len = 0;
			while (len < index-1){
				temp = temp->next;
				len++;
			}
			result = temp->num;
			temp = temp->next;
			result = result + temp->num;
			return result / 2;
		}
	}
}
