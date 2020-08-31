#include <iostream>

using namespace std;

#define MAXNUM 100001

void swap(unsigned int* a, unsigned int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

class myHEAP {
private:
	int idx;
	unsigned int heap[MAXNUM];

public:
	myHEAP() { // Default Constructor
		this->idx = 1;
		this->heap[0] = -1;
	}

	void push(int data) {
		// 가장 끝에 push
		heap[idx] = data;

		// swap 위한 tmp_idx
		int tmp_idx = idx;

		// idx(==size)는 1 증가
		idx++;

		while ((tmp_idx != 1) && (heap[tmp_idx] < heap[tmp_idx/2])) {
			// 입력한 데이터가 부모보다 작으면 계속해서 바꿈
			swap(&heap[tmp_idx], &heap[tmp_idx / 2]);
			tmp_idx = tmp_idx / 2;
		}

		return;
	}

	int pop() {
		// empty
		if (idx == 1) return 0;

		// not empty
		unsigned int returnValue = heap[1];

		// 맨 끝에 있는 것 앞으로 가져옴
		heap[1] = heap[idx - 1];
		
		// idx(==size) 1 감소
		idx--;
		
		// parent node and child
		int parent = 1;
		int child = parent * 2;

		// 자식과 비교하며 더 작은 것과 비교하며 내려옴
		while ((child < idx) && (heap[parent] > heap[child])) {

			// 자식 노드 중 더 큰 것 확인
			if ((child + 1 < idx) && (heap[child] > heap[child + 1])) child += 1;
			
			// swap child and parent node
			swap(&heap[child], &heap[parent]);

			// update child and parent
			parent = child;
			child = 2 * parent;
		}

		return returnValue;
	}

	void printHeap() {
		for (int i = 1; i < idx; i++) cout << heap[i] << ' ';
		cout << '\n';
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	myHEAP heap = myHEAP();

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		unsigned int num;
		cin >> num;

		if (num == 0) {
			cout << heap.pop() << '\n';
		}
		else heap.push(num);
	}

	return 0;
}