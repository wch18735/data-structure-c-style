// 이진탐색트리 => 탐색작업을 효율적으로 하기 위한 자료구조
// key(왼쪽 서브 트리) < key(루트노드) < key(오른쪽 서브 트리)
// 이진탐색을 중위순회(LVR)하면 오른차순으로 정렬된 값을 얻을 수 있다

// 왼쪽은 루트보다 작은 값, 오른쪽은 루트보다 큰 값
// 이진탐색트리에서 연산: 주어진 키 값이 루트노드 키 값보다 작으면 왼쪽, 크면 오른쪽으로 배치 시킨다

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;

/* 순환적인 방밥으로 이진탐색 */
TreeNode *search_iter(TreeNode *node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search_iter(node->left, key);
	else
		return search_iter(node->right, key);
}

TreeNode *search_recur(TreeNode *node, int key) {
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}	// 한 번의 while 루프마다 node 업데이트
	return NULL;		// 탐색에 실패했을 경우 NULL 반환
}
TreeNode *new_node(int item) {	// key(==item) 값을 가지는 새로운 노드 생성
	TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// 이진탐색트리에서의 삽입연산 => 탐색에 실패한 위치가 새로운 노드를 삽입하는 위치
TreeNode *insert_node(TreeNode *node, int key) {
	// 트리가 공백이면 새로운 노드 반환
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리 내려감
	if (key < node->key)	// key값이 노드의 key값보다 작으면
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	// key값에 따라 왼,오 판단하고 그곳이 NULL이면 그 위치에 생성하고 업데이트
	// 아니면 다시 그 곳 key값과 주어진 key값 비교

	// 변경된 루트 포인터를 반환한다
	return node;
}

void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);		// 왼쪽 서브트리 순회
		printf("[%d] ", root->key);	// 노드 방문 (print는 데이터에 접근한다는 뜻)
		inorder(root->right);		// 오른쪽 서브트리 순회
	}
}

// 이진탐색트리에서의 삭제 연산
// 1. 삭제하려는 노드가 단말 노드일 경우
// 2. 삭제하려는 노드가 하나의 왼쪽이나 오른쪽 서브 트리 중 하나만 가지고 있는 경우
// 3. 삭제하려는 노드가 두 개의 서브 트리 모두 가지고 있는 경우

// CASE1: 삭제하려는 노드가 단말 노드일 경우
// 간단하게 삭제 가능 (부모 노드에서 NULL 값으로 끊어주면 된다)

// CASE2: 삭제하려는 노드가 하나의 서브트리만 갖고 있는 경우
// 삭제 해당 노드를 삭제하고, 해당노드의 부모노드와, 해당노드의 자식노드를 붙여준다

// CASE3: 삭제하려는 노드가 두개의 서브트리를 갖고 있는 경우
// 삭제노드와 가장 비슷한 값을 가진 노드를 삭제 노드 위치로 가져온다
// 그렇다면 가장 비슷한 값은 어디에?
// 왼쪽 서브트리에서 제일 큰 값 or 오른쪽 서브트리에서 제일 작은 값 중 하나!!
// 원리: 이진탐색트리의 대소 관계는 프랙탈 구조
// 따라서 서브트리들 역시 중위순회시 오름차순으로 정리 가능
// 가운데 삭제 해당 노드의 양 옆이 위의 두 가지임

TreeNode *min_value_node(TreeNode *node) {
	TreeNode *current = node;
	//맨 왼쪽 단말 노드를 찾으러 내려간다
	while (current->left != NULL)
		current = current->left;

	return current;
}

TreeNode *delete_node(TreeNode *root, int key) {
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > root->key)
		root->right = delete_node(root->left, key);

	// 키가 루트와 같을 때 이 노드를 삭제
	else{
		if (root->left == NULL) {	// 왼쪽이 없을 때
			TreeNode *temp = root->right; // 반대쪽 반환
			free(root);
			return temp;
		}
		else if (root->right == NULL) {	// 오른쪽이 없을 때
			TreeNode *temp = root->left;	// 반대쪽 반환
			free(root);
			return temp;
		}

		// 세 번째 경우

		TreeNode *temp = min_value_node(root->right);

		// 중위 순회시 후계 노드를 복사한다
		root->key = temp->key;

		// 중위 순회시 후계 노드를 삭제한다
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

TreeNode *search(TreeNode *node, int key) {
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;
}

int main(void)
{
	TreeNode * root = NULL;
	TreeNode * tmp = NULL;
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");
	return 0;
}