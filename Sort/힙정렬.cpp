#include <stdio.h>

// First, Tree -> Binary Tree -> Complete Binary Tree
// Second, apply Heapify Algorithm
// Height Heapify algorithm Complexity: (log_2)N
// Number of node: N
// so, Actual Complexity is N/2*(log_2)N -> O(N*log(N))

// 메모리 측면에서 병합정렬보다 효율적
// 항상 O(N*log_2_^N)을 보장함 

int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void) {
	// 최대 힙 구조로 만드는 과정
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) { 
				// root < child
				// swap root and child
				int tmp = heap[c];
				heap[c] = heap[root];
				heap[root] = tmp;
			}
			c = root;
		} while (c != 0);
	}

	// 크기를 줄이며 반복적으로 힙 구성
	for (int i = number - 1; i >= 0; i--) {
		// i: right endline 
		// 교환
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		int root = 0;
		int c = 1;
		do {
			// root * 2 + 1 -> left child node
			c = 2 * root + 1;

			// 자식 비교
			if (heap[c] < heap[c + 1] && c < i-1) {
				c++;
			}
			// 자식 중 큰 값을 부모와 비교 후 자식이 크면 swap
			if (heap[root] < heap[c] && c < i) {
				int tmp = heap[c];
				heap[c] = heap[root];
				heap[root] = tmp;
			}

			// 바뀐 노드로부터 right endline 까지 Heapify 수행
			root = c;
		} while (c < i);
	}

	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}