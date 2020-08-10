#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

// 이진트리의 NULL 링크를 이용하여 순환 호출 없이도 트리의 노드들을 순회
// NULL 링크에 중위 순회시에 후속 노드인 중위 후속자 (inorder successor)를 저장시켜 놓은 트리가 스레드 이진 트리(threaded binary tree)
#define true 1

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	int is_thread; // 만약 오른쪽 링크가 스레드이면 True
} TreeNode;
// 단말 노드와 비단말노드의 구별을 위하여 is_thread 필드 필요

TreeNode *find_successor(TreeNode *p) {
	TreeNode *q = p->right;		// p 의 오른쪽 노드를 q에 저장
	if (q == NULL || p->is_thread == true) return q;	// q가 NULL이거나, p의 중위 후속자가 q라면 (is_thread == true) q리턴
	while (q->left != NULL) q = q->left;				// 오른쪽 자식노드가 NULL도, 중위 후속자도 아니라면 그것의 가장 왼쪽 노드로 이동
	return q;											// 가장 아래 왼쪽 노드 리턴
}

void thread_inorder(TreeNode *t) {
	TreeNode *q;
	q = t;
	while (q->left) q = q->left;	// 가장 왼쪽 노드로 이동
	do {
		printf("c", q->data);	// 데이터 출력
		q = find_successor(q);	// 후속자 함수 호출
	} while (q);				// NULL이 아니면
}

