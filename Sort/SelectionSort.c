#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<time.h>

// 정렬된 왼쪽 리스트와 정렬되지 않은 오른쪽 리스트를 가정
// 초기에 왼쪽 리스트는 비어있고, 정렬할 숫자들은 모두 오른쪽 리스트에 존재
// 오른쪽 리스트를 돌며 가장 작은(또는 큰) 값을 선택해서 왼쪽 리스트로 가져온다
// 이 과정을 리스트를 두 개 사용하지 않고 한 번에 처리하는 것

// 알고리즘
// for i <- 0 to n-2 do
//		least <- A[i], A[i+1], ... , A[n-1] 중에서 가장 작은 값의 인덱스;
//		A[i]와 A[least] 의 교환;
//		i++;
//		위에서 n-2 까지인 이유는 마지막 한 번은 굳이 비교할 필요 없음

#define MAX_SIZE 10
#define SWAP(x,y,t)((t) = (x), (x) = (y), (y) = (t))
int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n) {
	int i, j, least, temp;
	for (int i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)			// 최소값 탐색
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
	}
	// i => 고정된 비교할 위치의 index로 1식 증가
	// least => 돌면서 최소인 것 찾음
	// j => i의 다음 index
	// 왜 j < n 이지?
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i<n; i++) // 난수 생성 및 출력
		list[i] = rand() % 100; // 난수 발생 범위 0~99
	selection_sort(list, n); // 선택정렬 호출
	for (i = 0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

// 선택정렬 복잡도 분석
// 비교횟수: O(n**2)
// 이동횟수: 3(n-1)
// 전체 시간적 복잡도: O(n**2)
// 안정성을 만족하지 않음

