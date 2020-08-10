#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

int calc_dir_size(TreeNode *root) {
	int left_size, right_size;
	if (root == NULL) return 0;	// 아무것도 없으면 사이즈는 0
		// 따라서 left_size와 right_size를 초기화하지 않아도 맨 끝에서는 0이기 때문에 가능
	left_size = calc_dir_size(root->left);
	right_size = calc_dir_size(root->right);
	return(root->data + left_size + right_size);
} // 여기서 재귀는 본인 데이터 + 아래 두 크기를 받아오는데, 이때 분기시키면서 재귀함수 발동

int main(void)
{
	TreeNode n4 = { 500, NULL, NULL };
	TreeNode n5 = { 200, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5 };
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };
	printf("디렉토리의 크기=%d\n", calc_dir_size(&n1));
}