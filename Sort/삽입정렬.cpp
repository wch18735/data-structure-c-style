#include <stdio.h>

int main() {
	int numArr[10] = { 1,10,5,8,7,6,4,3,2,9 };

	int i, j, tmp;
	for (i = 0; i < 10; i++) {
		j = i;
		while (j > 0 && numArr[j-1] > numArr[j]){
			tmp = numArr[j];
			numArr[j] = numArr[j-1];
			numArr[j-1] = tmp;
			j--;
		}
	}

	for (int k = 0; k < 10; k++) {
		printf("%d ", numArr[k]);
	}

	return 0;
}