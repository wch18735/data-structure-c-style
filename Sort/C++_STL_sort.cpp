#include <iostream>
#include <algorithm> // 대표적인 STL

using namespace std;

bool compare(int a, int b);

int main(void) {
	int a[10] = { 9,3,5,4,1,1,8,4,7,2 };
	sort(a, a + 10); // sort(start memory point, end memory point)

	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i], compare);
	}
}

bool compare(int a, int b) {
	return a > b;
}