// 각 노드를 레벨 순으로 검사하는 순회법
// 지금까지 순회 법이 스택을 사용했던 것에 비해 레벨 순회는 큐를 사용하는 순회법

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

// ==== 원형큐 코드 시작 ====
// rear: 데이터가 있는 가장 끝
// front:데이터가 없는 가장 처음
// 원형 Dequeue에서는 Max_Size를 더한 다음 나눠주는 방식을 사용해 배열 밖으로 벗어나는 경우를 방지한다
// 원형 Queue는 기본적으로 시계방향으로 회전한다

#define MAX_QUEUE_SIZE 100
typedef TreeNode *element;
typedef struct { // 큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 오류함수
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 생성자 함수
void init_queue(QueueType *q) {
	q->front = q->rear = 0;
}

// 공백상태 검출 함수
int is_empty(QueueType * q) {
	return (q->front == q->rear); // 처음 시작상태와 같으면 empty
}

int is_full(QueueType * q) {
	return((q->rear+1)% MAX_QUEUE_SIZE == q->front);
}


// 배열에 성질을 부여하고 싶을 때는 배열을 struct 안에 집어넣고, 이를 감싸는 struct의 자료구조를 정해주면 된다 (현재는 circular_queue)
void enqueue(QueueType *q, element item) {		// 왼쪽, 오른쪽 노드를 가진 노드들을 배열에 집어넣는데, 이때 이는 큐의 형태를 가지는 배열 파이프임
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	/*(q->front + MAX_QUEUE_SIZE - 1) 이거는 front_delete 일 때*/
	return q->data[q->front];
}

void level_order(TreeNode *ptr) {
	QueueType q;	// TreeNode를 저장할 수 있는 Circle_Que 타입
	init_queue(&q);	// q의 front와 rear값 초기화	// struct를 통해 생성했으므로 레퍼런스와 메모리 공간 모두 존재~!!

	if (ptr == NULL)/* 노드가 없으면 */ return; /* 끝 */
	enqueue(&q, ptr); /* 노드가 존재하면 파이프에 추가 */
	while (!is_empty(&q)) { // 파이프가 빌 때까지 아래 동작을 실행한다
		ptr = dequeue(&q);	// 가장 나중에 들어온 Node 확인
		printf("[%d]", ptr->data);
		if (ptr->left) /* ptr의 왼쪽 노드가 존재하면 */
			enqueue(&q, ptr->left); // 해당 노드의 왼쪽을 추가한다
		if (ptr->right) /* ptr의 오른쪽 노드가 존재하면 */
			enqueue(&q, ptr->right); // 해당 노드의 오른쪽을 추가한다
	}
	/* 즉, dequeue로 밖으로 나갈 때, 자기 자신의 left, right를 하나씩 파이프에 집어넣고 나간다 */
	/* 이 순서대로라면 똑같이 그 줄에서 왼 쪽 -> 오른 쪽 순서로 진행된다  */
	/* 핵심은 1.나가면서 2.양 옆 추가 3. 순서대로 빼냄 */
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;
int main(void)
{
	printf("레벨 순회=");
	level_order(root);
	printf("\n");
	return 0;
}