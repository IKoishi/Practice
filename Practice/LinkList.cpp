#include <stdio.h>
#include <malloc.h>

typedef int elemtype;
typedef struct node {
	elemtype data;
	struct node* prior, * next;
}DLinkList;

DLinkList* initDLinkList();
DLinkList* createNode();
void insertBefore(DLinkList *pnode, elemtype data);
void insertAfter(DLinkList* pnode, elemtype data);
void insertAfterHead(DLinkList* head, elemtype data);

void main() {
	DLinkList *head = initDLinkList();
	
	insertAfterHead(head, 514);
	insertAfterHead(head, 520);
	insertAfterHead(head, 123);
}



DLinkList* initDLinkList() {
	DLinkList* head = (DLinkList*)malloc(sizeof(DLinkList));
	if (head == NULL) {
		printf("head空间分配失败\n");
		return NULL;
	}
	head->prior = NULL;
	head->next = NULL;
	return head;
}

DLinkList* createNode() {
	DLinkList* new_node = (DLinkList*)malloc(sizeof(DLinkList));
	if (new_node == NULL) {
		printf("new_node堆空间分配失败\n");
		return NULL;
	}
	return new_node;
}

void insertBefore(DLinkList* pnode, elemtype data) {
	DLinkList* new_node = createNode();
	new_node->data = data;
	new_node->next = pnode;
	new_node->prior = pnode->prior;
	pnode->prior->next = new_node;
	pnode->prior = new_node;
}

void insertAfter(DLinkList* pnode, elemtype data) {
	DLinkList* new_node = createNode();
	new_node->data = data;
	new_node->next = pnode->next;
	new_node->prior = pnode;
	pnode->next->prior = new_node;
	pnode->next = new_node;
}

void insertAfterHead(DLinkList* head, elemtype data) {
	DLinkList* new_node = createNode();
	new_node->data = data;
	if (head->next != NULL) {
		new_node->next = head->next;
		head->next->prior = new_node;
	}
	head->next = new_node;
	new_node->prior = head;
}