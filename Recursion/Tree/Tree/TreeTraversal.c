#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

// 사용자 정의 DataType
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	// TreeNode의 포인터 변수를 정의한다
} TreeNode;

// 사용자 정의 함수 (순회)
// 중위 순회
void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);		// 왼쪽 서브트리 순회
		printf("[%d] ", root->data);	// 노드 방문 (print는 데이터에 접근한다는 뜻)
		inorder(root->right);		// 오른쪽 서브트리 순회
	}
}

// 전위 순회
void preorder(TreeNode *root) {
	if (root) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// 후외 순회
void postorder(TreeNode *root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main() {
	TreeNode n1 = { 1, NULL, NULL };
	TreeNode n2 = { 4, &n1, NULL };
	TreeNode n3 = { 16, NULL, NULL };
	TreeNode n4 = { 25, NULL, NULL };
	TreeNode n5 = { 20, &n3, &n4 };
	TreeNode n6 = { 15, &n2, &n5 };
	TreeNode *root = &n6;

	printf("중위 순회=");
	inorder(root);
	printf("\n");
	printf("전위 순회=");
	preorder(root);
	printf("\n");
	printf("후위 순회=");
	postorder(root);
	printf("\n");
	return 0;
}





/* BinaryTree의 순회 */
/*
	1. 전위순회 (preorder traersal)
	: 자손노드보다 루트노드를 먼저 방문한다

	2. 중위순회 (inorder traversal)
	: 왼쪽 자손, 루트, 오른쪽 자손 순으로 방문한다

	3. 후위순회 (postorder traveral)
	: 루트노드보다 자손을 먼저 방문한다

	※ 순환호출을 이용한다
*/
