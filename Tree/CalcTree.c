// 수식트리: 산술식을 트리형태로 표현한 것
// 비단말노드: 연산자(operator)	:끝에 위치한 단자
// 단말노드: 피연산자(operand)	:끝이 아닌 단자
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode *exp = &n7;

int evaluate(TreeNode *root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL)/*단말노드이면*/ return root->data; /* 그 노드 값 반환 */
	else {	/* 단말 노드가 아니면 연산 작용 */
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d을 계산합니다.\n", op1, root->data, op2);
		switch (root->data) {
		case'+': return op1 + op2;
		case'-': return op1 - op2;
		case'*': return op1 * op2;
		case'/': return op1 / op2;
		}
	}
	return 0;
} // 기본적으로 재귀함수로 구현된다

int main(void) {
	printf("수식의 값은 %d 입니다.\n", evaluate(exp));
	return 0;
}

// 개인적으로 감명받음

/* 수식 트리 계산 */
// 후위순회를 사용한다: 왼쪽부터 접근하며 left, right 모두 null 일 때 Read
// 서브트리의 값을 순환호출로 계산
// 비단말노드를 방문할 때 양쪽 서브트리 값을 노드에 저장된 연산자를 이용해 계산함
// 이 말은 즉, 접근했을 때, 양쪽에 서브트리가 존재하면 그것은 피연산자가 있고,
// 본인은 연산자라는 뜻으로 바로 left->data 와 right->data를 가져와 연산한다는 뜻