/* Bubble Sort */
// 인접한 2개의 레코드를 비교하여 순서대로 되어 있지 않으면 서로 교환한다

/* 버블 정렬 알고리즘 */
/*
	for i <- n-1 to 1 do			// ~까지 인 index i가 1씩 줄어든다
		for j<-0 to i-1 do
			j와 j+1 번째의 요소가 크기 순이 아니면 교환
			j++;
		i--;
*/

#include<stdio.h>
#include<stdlib.h>

#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void bubble_sort(int list[], int n) {
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}
	}
}

// 비교 횟수 (최상, 평균, 최악의 경우 모두 일정)
// O(n**2)

// 이동 횟수
// 역순으로 정렬된 경우: 3*비교횟수
// 이미 정렬된 경우: 0
// 평균의 경우: O(n**2)

// 레코드의 이동 과다
// 이동연산은 비교연산보다 더 많은 시간이 소요된다
