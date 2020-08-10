// 차수가 2 또는 3인 노드를 가지는 트리

/* 2-노드 */
// 이진탐색트리처럼 하나의 데이터 k1와 두 개의 자식 노드를 가진다

/* 3-노드 */
// 2개의 데이터 k1,k2와 3개의 자식노드를 가진다

// 왼쪽 서브 트리에 있는 데이터들은 모두 k1보다 작은 값이다
// 중간 서브 트리에 있는 값들은 모두 k1보다 크고 k2보다 작다
// 오른쪽에 있는 데이터들은 모두 k2보다 크다

Tree23Node *tree23_search(Tree23Node* root, int key)
{
	if (root == NULL)			// 트리가 비어 있으면
		return FALSE;
	else if (key == root->data)// 루트의 키==탐색키 
		return TRUE;
	else if (root->type == TWO_NODE) {  // 2-노드
		if (key < root->key)
			return tree23_search(root->left, key);
		else
			return tree23_search(root->right, key);
	}
	else {										// 3-노드
		if (key < root->key1)
			return tree23_search(root->left, key);
		else if (key > root->key2)
			return tree23_search(root->right, key);
		else
			return tree23_search(root->middle, key);
	}
}