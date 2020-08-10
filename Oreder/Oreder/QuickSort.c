#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

/* 퀵 정렬 */
// 평균적으로 가장 빠른 정렬 방법
// 분할정복법 사용
// 리스트를 2개의 부분 리스트로 비균등 분할하고, 각각의 부분 리스트를 다시 퀵정렬함(재귀호출)

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do 
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);	// 멈춘 곳에서 Swqp 해줌
	} while (low < high);	// 모든 검사 완료

	SWAP(list[left], list[high], temp);
	return high;	// High는 Pivot의 위치
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {	// q = 는 피벗의 위치
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++) // 난수 생성 및 출력
		list[i] = rand() % 100;
	quick_sort(list, 0, n - 1); // 퀵정렬 호출
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

/* 퀵  정렬 복잡도 분석 */
// 최선의 경우: 거의 균등한 리스트로 분할되는 경우
// 패스 수: log(n)
// 각 패스 안에서의 비교 횟수: n
// 총 비교횟수: n*log(n)

// 최악의 경우: 극도로 불균등한 리스트로 분할되는 경우
// 패스 수: n
// 각 패스 안에서 비교횟수: n
// 총 비교횟수: n**2
// 중간 값을 피벗으로 선택하면 불균등 분할 완화 가능

