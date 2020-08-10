#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10
int sorted[MAX_SIZE];
// i는 정렬된 왼쪽 리스트에 대한 인덱스
// j는 정렬된 오른쪽 리스트에 대한 인덱스
// k는 정렬된 리스트에 대한 인덱스

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// 분할 정렬된 list의 합병
	while (i<=mid && j <= right){
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid)	// 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	//배열 sorted[]의 리스트를 배열 list[]로 복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;			// 리스트의 균등분할
		merge_sort(list, left, mid);		// 부분 리스트 정렬
		merge_sort(list, mid + 1, right);	// 부분 리스트 정렬
		merge(list, left, mid, right);		// 합병
	}
}

/* 합병 정렬 복잡도 분석 */
// 비교 횟수: 크기 n인 리스트를 정확히 균등분배하므로 log(n) 개의 패스
// 각 패스에서 리스트의 모든 레코드 n개를 비교하므로 n번의 비교 연산

/* 이동 횟수 */
// 레코드의 이동이 각 패스에서 2n번 발생하므로 전체 레코드의 이동은 2n*log(n)번 발생
// 레코드의 크기가 큰 경우에는 매우 큰 시간적 낭비 초래
// 레코드를 연결 리스트로 구성하여 합병 정렬할 경우, 매우 효율적
// 최적, 평균, 최악의 경우 큰 차이 없이 O(n*log(n)) 의 복잡도
// 안정적이며 데이터의 초기 분산 순서에 영향을 덜 받는다




// 1. 리스트를 두 개의 균등한 크기로 분할하고 분할된 리스트를 정렬
// 2. 정렬된 두 개의 부분 리스트를 합하여 전체 리스트를 정렬한다

// 분할, 정복, 결합 알고리즘을 사용한다.
// 1. 분할(divide): 배열을 같은 크기의 2개의 부분 배열로 분할
// 2. 정복(conquer): 부분 배열을 정렬하는데, 부분 배열의 크기가 충분히 작지 않으면 재귀호출을 이용하여 다시 분할정복기법을 적용한다
// 3. 결합(Combine): 정렬된 부분배열을 하나의 배열에 통합한다

/* 합병정렬 알고리즘 */
/*
	if left<right
		mid = (left+right)/2;
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, right);
		merge(list, left, mid, right);
*/

/* 합병 알고리즘 */
/*
	i <- left;
	j <- mid+1
	k <- left;
	while i < mid and j <right do
		if(list[i] < mid[j])
				then
					sorted[k] <- list[i];
					k++;
					i++;
				else
					sorted[k] <- mid[j];
					k++;
					j++;
	요소가 남은 부분 배열을 sorted 로 복사한다;
	sorted를 list로 복사한다
*/

