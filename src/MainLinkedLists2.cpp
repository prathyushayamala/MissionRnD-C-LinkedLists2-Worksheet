/*

Use MainLinkedLists2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.

Objectives of LinkedLists2 Lesson:

->Merging two Linked Lists
->Reversing a LinkedList
->Inserting at a specific index 

*/
#include <stdio.h>
#include<stdlib.h>
#include "FunctionHeadersLinkedLists2.h"
struct node {
	int num;
	struct node *next;
};

struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * createList(int num) {
	struct node *head = createNode(num % 10);
	num /= 10;
	while (num) {
		struct node *newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	}
	return head;
}

int main(){

	struct node* res=merge2LinkedLists(createList(123), createList(123));
	//Test InsertAtEveryKthNode

	//Test LinkedListMedian

	//Test merge2 LinkedLists

	//Test reverse LinkedList

	return 0;
}