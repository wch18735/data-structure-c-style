#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define MAX_ELEMENT 200
#define SIZE 8
typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 생성 함수
HeapType *create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType *h) {
	h->heap_size = 0;
}

// 삽입 함수
void insert_max_heap(HeapType *h, element item) {
	int i;
	i = ++(h->heap_size);

	// 트리를 거슬러 올라가며 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {	// 판단
		h->heap[i] = h->heap[i / 2];	// 부모 노드의 key값을 끝으로 추가
		i /= 2;							// 부모 노드로 index값 Update
	}	// Index 위치만 기억함 (이미 입력할 key값은 알고있으니 상관 없음)
	// while이 끝난 i 값이 heap을 만족하는 index값
	h->heap[i] = item;
}

// 삭제 함수
element delete_max_heap(HeapType *h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];	// root노드 넣음
	temp = h->heap[(h->heap_size)--];	// 가장 마지막 노드 temp에 넣고, size 줄임
	parent = 1;
	child = 2;
	while (child <= h->heap_size){	// 판단하려는 자식 노드가 마지막 index를 벋어나면 break
		// 현재 노드의 자식노드 중 더 큰 자식노드 찾기
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;	// 오른쪽이 더 크면 오른쪽, 아니면 그대로 왼쪽
		if (temp.key >= h->heap[child].key) break; // 만족하면 그대로 break;

		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];	// 부모 위치에 자식 넣음
		parent = child;	// 부모 노드를 update;
		child *= 2;		// 해당 노드의 왼쪽 자식노드 index로 update
	}
	h->heap[parent] = temp;	// 부모노드 자리에 temp를 넣음
	return item;
}

void heap_sort(element a[], int n) {
	int i;
	HeapType *h;

	h = create();
	init(h);
	for (i = 0; i < n; i++)
		insert_max_heap(h, a[i]);
	for (i = (n - 1); i >= 0; i--)
		a[i] = delete_max_heap(h);	// 이렇게 하면 오름차순정리
	/*
	for (i = 0; i < n; i++)
		a[i] = delete_max_heap(h);	// 이렇게 하면 내림차순
	*/
	free(h);	// 메모리 할당 해제
}

int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;
	heap = create(); // 히프 생성
	init(heap); // 초기화
				// 삽입
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	// 삭제
	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > \n", e6.key);
	free(heap);

	element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}