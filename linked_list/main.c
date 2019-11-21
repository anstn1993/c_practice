#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct node {/* ��� ����ü */
	int value;
	struct node_t* next;
} node_t;

void print_linkedlist(node_t* head)/* linkedlist�� ��带 ��� ��� */
{
	node_t* p;
	p = head;
	while (p != NULL) {
		printf("(%d, %X) ", p->value, p->next);
		p = p->next;
	}
	printf("\n");
}

void destroy(node_t* head)/* linkedlist�� �Ҵ�� ��� �޸� ���� */
{
	node_t* p = head;
	while (p != NULL) {
		node_t* tmp = p->next;/* ���� ��� ���� */
		free(p);/* ���� ��� ���� */
		p = tmp;/* ���� ���� �̵� */
	}
}

void insert_front(node_t** phead, int n)/* ���� �տ� ������ �߰� */
{
	node_t* new_node;
	new_node = malloc(sizeof(node_t));
	new_node->value = n;
	new_node->next = *phead;
	*phead = new_node;
}

void insert_back(node_t** phead, int n)/* ���� �ڿ� ������ �߰� */
{
	node_t** pp;
	node_t* new_node;
	new_node = malloc(sizeof(node_t));
	new_node->value = n;

	pp = phead;
	if (*pp == NULL) {
		*pp = new_node;
		return;
	}

	while (*pp != NULL) {
		if ((*pp)->next == NULL) {
			(*pp)->next = new_node;
			break;
		}
		pp = &(*pp)->next;
	}
}

void insert_sorted(node_t** phead, int n)/* ������ �Է½� �ڵ����� �������� ���� */
{
	node_t** pp;
	node_t* new_node;
	new_node = malloc(sizeof(node_t));
	new_node->value = n;
	pp = phead;
	while (*pp != NULL) {
		if ((*pp)->value >= n) {
			break;
		}
		pp = &(*pp)->next;
	}
	new_node->next = *pp;
	*pp = new_node;
}

void remove_node(node_t** phead, int n)/* ��� ���� */
{
	node_t** pp;

	pp = phead;

	while (*pp != NULL) {
		if ((*pp)->value == n) {
			node_t* tmp = *pp;
			*pp = (*pp)->next;
			free(tmp);
			break;
		}
		pp = &(*pp)->next;
	}
}

int main(void)
{
	node_t* head = NULL;
	
	insert_front(&head, 3);
	insert_front(&head, 5);
	insert_front(&head, 2);
	insert_front(&head, 0);
	printf("%s", "====insert first(3, 5, 2, 0)====\n");
	print_linkedlist(head);
	printf("%s", "====insert back(7, 8, 9, 10)====\n");
	insert_back(&head, 7);
	insert_back(&head, 8);
	insert_back(&head, 9);
	insert_back(&head, 10);
	print_linkedlist(head);
	destroy(head);
	head = NULL;

	printf("%s", "====insert sorted(2, 5, 4, 1)====\n");
	insert_sorted(&head, 2);
	insert_sorted(&head, 5);
	insert_sorted(&head, 4);
	insert_sorted(&head, 1);
	print_linkedlist(head);	
	printf("%s", "====remove 1, 5====\n");
	remove_node(&head, 1);
	remove_node(&head, 5);
	print_linkedlist(head);

	destroy(head);
	head = NULL;
}