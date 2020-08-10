#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

/*
			<구현 트리>
				n1
			↙		↘
		  n2		  n3
*/


int main() {
	// 변수 선언 (레퍼런스 선언)
	TreeNode *n1, *n2, *n3;

	// 메모리 할당
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));

	n1->data = 10;
	n1->left = n2;
	n1->right = n3;

	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;

	n3->data = 30;
	n1->left = NULL;
	n1->right = NULL;
}






/* 이진트리의 표현 */
/* 
	1. 배열을이용한 표현
	모든 이진트리를 포화 이진 트리라고 가정하고 각 노드에 번호를 붙여서그 번호를 배열의 인덱스로 삼아 노드의 데이터를 배열에 저장하는 방법
	노드 i의 부모 노드 인덱스 = i/2
	노드 i의 왼쪽 자식 노드 인덱스 = 2i
	노드 i의 오른쪽 자식 노드 인덱스 = 2i + 1
*/


/*
	2. 링크 표현법
	포인터를 이용하여 부모노드가 자식노드를 가리키게 하는 방법
*/