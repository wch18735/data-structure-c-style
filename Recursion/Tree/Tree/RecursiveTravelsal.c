#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p) {
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode* pop() {		// Q.전달 인자가 없어도 될까?
						// A.없어도 된다. 전역 변수로 설정했기 때문!!
	TreeNode *p = NULL;
	if (top >= 0) p = stack[top--];	// stack 도 전역변수
	return p;
}

void inorder_iter(TreeNode *root) {
	while (1) {
		for (; root; root = root->left)				// 맨 왼쪽 Node를 찾아간다!!
			push(root);								// stack에 추가한다					
		root = pop();								// root가 NULL 값에서 하나 이전 값을 가리키게 함
		if (!root) break;	// root -> NULL 이면!!
		printf("[%d]", root->data);					// 해당 자리에서 printf 접근
		root = root->right;							// 오른쪽 포인터 root에 저장 (없으면 null)
													// null 이면 left 검사없이 그대로 하나 위로 올라감
													// 있으면 stack에 저장

		/* 즉, 가장 왼쪽 값을 찾고, 중간을 거치고, 이후 오른쪽으로 이동하는 중위순회를 구현함*/
	}
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;

int main(void) {
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
}