#include<stdio.h>
#include<stdlib.h>

// 삽입 정렬이 어느 정도 정렬된 리스트에서 대단히 빠른 것에 착안한다
// 삽입 정렬은 요소들이 이웃한 위치로만 이동하므로, 많은 이동에 의해서만 요소가 제자리를 찾아간다
// 요소들이 멀리 떨어진 위치로 이동할 수 있게하면, 보다 적게 이동하여 제자리를 찾을 수 있다 
// (while 로 계속 당겨주는 작업하지 않아도 된다)
// 전체 리스트를 일정 간격(Gap)의 부분 리스트로 나눈다
// 나뉘어진 각각의 부분리스트를 삽입정렬한다

// gap 만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last

void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {	// gap씩 증가한다
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + 1] = key;
	}
}	// Gap 가지고 정렬하는 코드

void shell_sort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}	// gap을 이용해 정렬하는 코드를 gap의 크기변화에 대해, index를 0~n-1 까지 변화시키며 정렬하는 알고리즘

/* 셸 정렬 복잡도 분석 */
// 셸 정렬의 장점
// 불연속적인 부분 리스트에서 원거리 자료 이동으로 보다 적은 위치교환으로 제자리 찾을 가능성 증대
// 부분리스트가 점진적으로 정렬된 상태가 되므로 속도 증가

// 시간적 복잡도
// 최악의 경우: O(n**2)
// 평균적인 경우: O(n**1.5)


