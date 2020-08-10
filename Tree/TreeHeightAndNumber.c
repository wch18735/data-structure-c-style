/* 이진 트리 연산: 노드 개수와 높이 */
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

int get_node_count(TreeNode *node) {
	int count = 0;
	if (node != NULL) {
		count = 1 /* 현재 '본인 상태' 반환 */ + get_node_count(node->left) /* 본인 왼쪽 아래 노드 개수 반환 */ + get_node_count(node->right) /* 본인 오른쪽 아래 노드 개수 반환 */;
	}
	return count;
}

int get_height(TreeNode *node) { // 맨 밑부터 현재까지 높이 반환
	int height = 0;
	if (node != NULL) //노드가 NULL이 아니면!!
		height = 1 + max(get_height(node->left), get_height(node->right));
	// max 함수는 stdlib.h에서 사용하는 것
	// height의 끝은 1반환 (null 이면 함수에서 0반환하므로)
	return height; // 분기의 중간에서는 끝부터 현재까지 height를 넘겨준다
}

int get_leaf_count(TreeNode *node) {
	/*내가 짠 코드*/
	// int count = 0;
	// if (node == NULL) return 1;
	// return count + get_leaf_count(node->left) + get_leaf_count(node->right);

	// if(node == NULL) return 1; 을 하면 단말노드에서 2의 값이 올라오게 된다. (양 쪽에서 1씩 받음)

	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
	} return count;
}

/* 
재귀함수를 꾸밀 때에는 지금 작성하고있는, 
인자로 받은 상태가 중간분기점이라고 가정한다. 
여기에 더해 맨 마지막에 반환되는 값을 생각해본다.
example로 null 값일 때 0 or 1이나 어떤 값이 반환되는지를 확인
*/