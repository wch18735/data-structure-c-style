#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	int rear, front;
	element data[MAX_QUEUE_SIZE];
} QueCircle;

// QueCircle 의 함수들
// init_QueCircle(&q)			: 생성
void init_QueCircle(QueCircle *q) {
	q->front = 0;
	q->rear = 0;
}

// is_full(&q)					: 가득 차있는지 확인
int is_full(QueCircle *q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

// is_empty(&q)					: 비었는지 확인
int is_empty(QueCircle *q) {
	return q->front == q->rear;
}

// Error 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// element dequeue(&q)			: 맨 앞에서 뽑고 삭제
element dequeue(QueCircle *q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->data[q->front] = '\0';					// 초기화 시키기
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // front를 한 칸 앞으로 옮긴다
	return q->data[q->front];
}

// void enque(&q, element item)	: 맨 뒤에 추가
void enqueue(QueCircle *q, element item) {
	if (is_full(q)) error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// element peek(&q)				: 뽑아내기만 함
element peek(QueCircle *q) {
	if (is_empty(q)) error("공백에러입니다");
	return q->data[q->front + 1];
}

// 원형큐 출력 함수
void queue_print(QueCircle *q) {
	printf("QUEUE(fornt=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);				//  i = i + 1 보다 i = (i + 1) % MAX_QUEUE_SIZE 로 저장
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}


int main() {
	QueCircle q;
	int element;

	init_QueCircle(&q);
	printf("---- 데이터 추가 단계 -----\n");
	while (!is_full(&q))
	{
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&q, element);
		queue_print(&q);
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("---- 데이터 삭제 단계 ----\n");
	while (!is_empty(&q))
	{
		element = dequeue(&q);
		printf("꺼내진 정수: %d\n", element);
		queue_print(&q);
	}
	printf("큐는 공백상태입니다");
	return 0;
}