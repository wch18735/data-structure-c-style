#include <iostream>

using namespace std;

#define maxNum 200001
#define maxValue (2<<31)-1

void print_heap(unsigned int* heap, int n) {
	for (int i = 0; i < n; i++) {
		cout << heap[i] << ' ';
	} cout << endl;

}

void push_heap(unsigned int* heap, int idx, unsigned int value) {
	while (idx != 0) {
		if (idx == 1) {
			heap[idx] = value;
			break;
		}
		else if (value < heap[idx / 2]) {
			heap[idx] = heap[idx / 2];
			idx = idx / 2;
		}
		else {
			heap[idx] = value;
			break;
		}
	}
}

int pop_heap(unsigned int* heap, int idx) {
	if (idx == 1) {
		heap[idx] = maxNum;
		return heap[idx];
	}

	int poped = heap[1];
	int limit = idx - 1;

	heap[1] = heap[idx - 1];
	heap[idx - 1] = maxValue;
	idx = 1;

	while (idx < limit) {
		int tmp = heap[idx];
		if (heap[idx * 2] < heap[idx * 2 + 1]) {
			if (heap[idx] > heap[idx * 2]) {
				heap[idx] = heap[idx * 2];
				heap[idx * 2] = tmp;
				idx = idx * 2;
			}
			else break;
		}
		else {
			if (heap[idx] > heap[idx * 2 + 1]) {
				heap[idx] = heap[idx * 2 + 1];
				heap[idx * 2 + 1] = tmp;
				idx = idx * 2 + 1;
			}
			else break;
		}
	}

	return poped;
}

int main(void) {
	unsigned int minimum_heap[maxNum];
	fill_n(minimum_heap, maxNum, (2<<31) - 1);
	
	int idx = 1;
	unsigned int num;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num == 0) {
			if (idx == 1) cout << 0 << endl;
			else {
				cout << pop_heap(minimum_heap, idx) << endl;
				idx--;
			}
		}
		else {
			push_heap(minimum_heap, idx, num);
			idx++;
		}
	}
	
	return 0;
}