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
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = e;
	p->link = head;	// p가 head가 가리키는 곳
	head = p;		// head 는 p를 가리킨다
	return head;
}

// 노드의 중간에 추가 (삽입연산)
ListNode* insert(ListNode *head, ListNode *pre, element e) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode*));
	p->data = e;
	p->link = pre->link;
	pre->link = p;
	return head;
} // pre 다음에 추가

// 노드의 시작부분 삭제
ListNode* delete_first(ListNode* head) {
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// 노드의 중간부분 삭제
ListNode* delete_mid(ListNode* head, ListNode *pre) {
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

// 노드의 리스트 모두 프린트
void print_list(ListNode *head) {
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

// 특정 값 찾아내는 함수
ListNode* search_list(ListNode* head, element e) {
	ListNode *p = head;
	while (p != NULL)
	{
		if (p->data == e) return p;	// 있으면 해당 노드 반환
		p = p->link;				// 아니면 계속 진행
	}
	return NULL;
}

// 두 개의 리스트를 합치는 함수
ListNode* concat_list(ListNode *head1, ListNode *head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode *p;
		p = head1;
		while (p->link !=NULL)		// 끝까지 보냄
			p = p->link;
		p->link = head2;
		return head1;
	}
}

// 역순으로 구성하는 함수
ListNode *reverse(ListNode *head) {
	ListNode *r, *q, *p;
	p = head;	// p는 역순으로 만들 리스트
	q = NULL;	// q는 역순으로 만들 노드
	while (p != NULL){
		r = q;
		q = p;
		p = p->link;	// 세팅

		q->link = r;	// 역순으로 변환
	}
	return q;			// 이제 역순이 헤드이다!!!
						// 역기서 head = q; 다음 head 반환해도 가능
}

// Test
int main() {
	ListNode *head = NULL;
/*  연습1
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	return 0; 
*/

}