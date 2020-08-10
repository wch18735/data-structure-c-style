#include<stdio.h>
#include<stdlib.h>

// 노드 정의
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

/* 노드 연산 */
// 노드의 시작부분에 추가
ListNode* insert_first(ListNode *head, element e) {
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	if (head == NULL) {		// 서로 연결
		head = node;
		node->link = head;
	}
	else {					// 아닐 경우
		node->link = head->link;
		head->link = node;
	}
	return head;
}

// 노드의 끝에 삽입
ListNode* insert_last(ListNode* head, element e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	if (head == NULL) {		// head가 레퍼런스만 존재하는지 아니면 객체도 같이 존재하는지 확인
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;		// 맨 끝의 노드를 head로 한다
	}
	return head;
}

// 노드의 처음 삭제
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	removed = head->link;
	head->link = removed->link;
	free(removed);
	return head;
}

// 노드의 마지막 삭제
ListNode* delete_last(ListNode* head) {
	ListNode* removed;
	removed = head;
	while (removed->link != head)	// head 바로 전으로
		removed = removed->link;
	head = removed;
	removed = removed->link;
	head->link = removed->link;
	free(removed);
	return head;
}

// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // 마지막 노드 출력
}


int main(void)
{
	ListNode *head = NULL;
	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	head = delete_first(head);
	head = delete_last(head);
	print_list(head);
	return 0;
}