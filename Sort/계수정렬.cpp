#include <stdio.h>

// 범위가 정해져있을 때, 개수를 새기만 하면 되는 경우
// O(n) 으로 접근 가능

int main() {
	int numArr[30] = { 1,1,3,2,4,3,2,5,3,1,2,3,4,4,3,5,1,2,3,5,2,3,1,4,3,5,1,2,1,1 };
	int arrCount[5] = { 0, };

	for (int i = 0; i < 30; i++) {
		arrCount[numArr[i]-1]++;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < arrCount[i]; j++) {
			printf("%d ", i + 1);
		}
	}
}