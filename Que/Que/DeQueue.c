#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}DEQUE;


/* 덱의 구성요소 */

// error()
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// init(dq)
void init(DEQUE *q) {
	q->front = 0;
	q->rear = 0;
}

// is_empty(dq)
int is_empty(DEQUE *q) {
	return (q->front == q->rear);
}

// is_full(dq)
int is_full(DEQUE *q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

// add_front(dq,e)
void add_front(DEQUE *q, element e) {
	if (is_full(q)) error("포화 에러");
	q->data[q->front] = e;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

// add_rear(dq,e)
void add_rear(DEQUE *q, element e) {
	if (is_full) error("포화 에러");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = e;
}

// delete_front(dq)
int delete_front(DEQUE *q) {
	if (is_empty(q)) error("공백 에러");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// delete_rear(dq)
int delete_rear(DEQUE *q) {
	if (is_empty(q)) error("공백 에러");
	int e;
	e = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return e;
}

// get_front(q)
int get_front(DEQUE *q) {
	if (is_empty(q)) error("공백 에러");
	return q->data[(q->front + 1)%MAX_QUEUE_SIZE];
} // get에서도 %MAX로 나눠줘야한다

// get_rear(q)
int get_rear(DEQUE *q) {
	if (is_empty(q)) error("공백 에러");
	return q->data[q->rear];
}



int main() {
	DEQUE q;
	init(&q);

	for (int i = 0; i < 3; i++) {
		add_front(&q,i);
		printf("%d\n", get_front(&q));
	}
	for (int i = 0; i < 3; i++) {
		printf("%d\n",delete_rear(&q));
	}
	return 0;
}


/*
double-ended queue 의 약자로 양쪽에서 입출력 가능하다
조절은 front와 rear 두 변수로 실시하며 형태는 원형이다.
원형큐와 비교해 원래 없던 함수: add_front, delete_rear
원형큐와 비교해 원래 있던 함수: add_rear == enqueue, delete_front == dequeue
함수가 진행될 때 방향을 주의하며
delete_rear 에서는 업데이트로 rear = (rear-1+MAX) % MAX 를 진행한다.
add_front 에서는 역시 업데이트로 front = (front-1+MAX) % MAX 를 진행한다.
스택과 큐의 연산을 모두 가지고 있다.
*/