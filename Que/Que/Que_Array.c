#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {								// Quetype의 Abstract Data Type 구조 만들기
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;
// front: 현재 비어있는 가장 처음
// rear: 현재 data가 차있는 끝


// 오류 함수
void error(const char *message) {						// 오류 만드는 함수
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q) {					// 큐를 초기화: front와 rear를 모두 -1로 초기화시킨다
	q->front = -1;
	q->rear = -1; 
}

void queue_print(QueueType *q) {				// 큐를 프린트하기
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || q->rear < i)		// 영역의 바깥쪽이면 (front => 그 곳까지 빈 곳, reat => Data가 차있는 끝 부분)
			printf("  |");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int is_full(QueueType *q) {						// Full 인지 확인하는 차있는 함수 (rear == MAX_QUEUE_SIZE - 1 이면)
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else return 0;
}

int is_empty(QueueType *q) {					// Empty 인지 확인하는 함수 (front == rear 이면 빈 것)
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
	
void enqueue(QueueType *q, int item) {			// 집어넣는 것 
	if (is_full(q))								// is_full 안에 is_full(q) 를 꼭 명시해주기
		error("포화 에러");
	else q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q) {						// 뽑아내는 것 (초기화 시키면서 이동한다)
	if (is_empty(q)) {							// is_empty 안에 is_empty(q) 를 꼭 명시해주기
		error("공백 에러");
		return -1;
	}
	// q->data[q->front] = NULL;				Why 초기화 넣으면 동작X ??r
	return q->data[++(q->front)];
}

int main(void) {
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
}