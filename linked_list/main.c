#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct node {/* 노드 구조체 */
	int value;
	struct node_t* next;
} node_t;

void print_linkedlist(node_t* head)/* linkedlist의 노드를 모두 출력 */
{
	node_t* p;
	p = head;
	while (p != NULL) {
		printf("(%d, %X) ", p->value, p->next);
		p = p->next;
	}
	printf("\n");
}

void destroy(node_t* head)/* linkedlist에 할당된 모든 메모리 해제 */
{
	node_t* p = head;
	while (p != NULL) {
		node_t* tmp = p->next;/* 다음 노드 저장 */
		free(p);/* 현재 노드 삭제 */
		p = tmp;/* 다음 노드로 이동 */
	}
}

void insert_front(node_t** phead, int n)/* 가장 앞에 데이터 추가 */
{
	node_t* new_node;
	new_node = malloc(sizeof(node_t));
	new_node->value = n;
	new_node->next = *phead;
	*phead = new_node;
}

void insert_back(node_t** phead, int n)/* 가장 뒤에 데이터 추가 */
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

void insert_sorted(node_t** phead, int n)/* 데이터 입력시 자동으로 오름차순 정렬 */
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

void remove_node(node_t** phead, int n)/* 노드 삭제 */
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