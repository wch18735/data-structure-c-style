#include <stdio.h>

int main() {
	int numArr[10] = { 10,3,7,2,4,9,1,5,8,6 };

	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10 - i; j++) {
			int tmp;
			if (numArr[j] > numArr[j + 1]) {
				tmp = numArr[j + 1];
				numArr[j + 1] = numArr[j];
				numArr[j] = tmp;
			}
		}
	}

		for (int i = 0; i < 10; i++) {
			printf("%d ", numArr[i]);
		}
}