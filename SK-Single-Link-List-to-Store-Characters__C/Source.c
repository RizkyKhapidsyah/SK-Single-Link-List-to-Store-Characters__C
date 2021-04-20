#pragma warning(disable:4996)

/* Created by CppBuzz
* Modified by Rizky Khapidsyah
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	char data;
	struct node* next;
} *head;


int countNodes() {
	struct node* n;
	int c = 0;
	n = head;

	while (n != NULL) {
		n = n->next;
		c++;
	}

	return c;
}

void appendNode(char newdata) {
	struct node* temp, * right;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = newdata;
	right = (struct node*)head;
	
	while (right->next != NULL) {
		right = right->next;
	}
		
	right->next = temp;
	right = temp;
	right->next = NULL;
}


void addNode(char newdata) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = newdata;

	if (head == NULL) {
		head = temp;
		head->next = NULL;
	} else {
		temp->next = head;
		head = temp;
	}
}

void addNodeafter(char newdata, int loc) {
	int i;
	struct node* temp, * left, * right;
	right = head;

	for (i = 1; i < loc; i++) {
		left = right;
		right = right->next;
	}
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = newdata;
	left->next = temp;
	left = temp;
	left->next = right;
	
	return;
}

void insertNode(char newdata) {
	int c = 0;
	struct node* temp;
	temp = head;
	
	if (temp == NULL) {
		addNode(newdata);
	} else {
		while (temp != NULL) {
			if (temp->data < newdata)
				c++;
			temp = temp->next;
		}
		
		if (c == 0) {
			addNode(newdata);
		} else if (c < countNodes()) {
			addNodeafter(newdata, ++c);
		} else {
			appendNode(newdata);
		}
			
	}
}

int deleteNode(char newdata) {
	struct node* temp, * prev;
	temp = head;

	while (temp != NULL) {
		if (temp->data == newdata) {
			if (temp == head) {
				head = temp->next;
				free(temp);
				return 1;
			} else {
				prev->next = temp->next;
				free(temp);
				return 1;
			}
		} else {
			prev = temp;
			temp = temp->next;
		}
	}

	return 0;
}

void  displayNode(struct node* r) {
	r = head;
	
	if (r == NULL) {
		return;
	}
	
	while (r != NULL) {
		printf(" %c ", r->data);
		r = r->next;
	}

	printf("\n");
}

int  main() {
	int i;
	char data;
	struct node* n;
	head = NULL;
	
	while (1) {
		printf("\nList Operations\n");
		printf("===============\n");
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Size\n");
		printf("4.Delete\n");
		printf("5.Exit\n");
		printf("Enter your choice : ");

		if (scanf("%d", &i) <= 0) {
			printf("Enter only an Integer\n");
			exit(0);
		} else {
			switch (i) {
			case 1:
				printf("Enter the char to insert : ");
				scanf(" %c", &data);
				insertNode(data);
				break;
			case 2:
				if (head == NULL) {
					printf("List is Empty\n");
				} else {
					printf("Element(s) in the list are : ");
				}

				displayNode(n);
				break;
			case 3:
				printf("Size of the list is %d\n", countNodes());
				break;
			case 4:
				if (head == NULL) {
					printf("List is Empty\n");
				}
				else {
					printf("Enter the number to deleteNode : ");
					scanf(" %c", &data);
				}

				if (deleteNode(data)) {
					printf(" %c delete Node successfully\n", data);
				}
				else {
					printf(" %c not found in the list\n", data);
				}

				break;
			case 5:     
				return 0;
			default:    
				printf("Invalid option\n");
			}
		}
	}

	_getch();
	return 0;
}