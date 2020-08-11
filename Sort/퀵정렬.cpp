#include <stdio.h>

// QuickSort() 의 구현은 재귀함수를 이용
// 최악의 경우 n^2 이 될 수 있음 (정렬이 이미 되어있는 경우)

int numArr[10] = { 3,7,8,1,5,9,6,10,2,4 };

void quickSort(int *data, int start, int end) {
	if (start >= end) { // 원소가 한 개인 경우
		return;
	}

	int key = start;
	int i = start + 1; // 왼쪽 출발지점
	int j = end; // 오른쪽 출발지점

	int tmp;

	while (i <= j) { // 엇갈리지 않을 때까지
		while (data[i] <= data[key]) { //key 값보다 큰 것 찾을 때까지
			i++;
		}
		while (data[j] >= data[key] && j > start) { //key 값보다 작은 것 찾을 때까지
			j--;
		}
		if (i > j) { // 엇갈렸다면
			tmp = data[j];
			data[j] = data[key];
			data[key] = tmp;
		}
		else {
			tmp = data[j];
			data[j] = data[i];
			data[i] = tmp;
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main() {
	quickSort(numArr, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", numArr[i]);
	}
}