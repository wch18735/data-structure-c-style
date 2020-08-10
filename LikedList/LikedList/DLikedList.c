#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
} DlistNode;

// insert
void dinsert(DlistNode *before, element e) {
	DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy(newnode->data, e);
	newnode->llink = before;
	newnode->llink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DlistNode* head, DlistNode* removed) {
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

int main() {

}