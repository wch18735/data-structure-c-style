// 삽입 정렬 (insertion sort)
// 정렬되어 있는 부분에 새로운 레코드를 원래 위치에 삽입하는 과정 반복
// 선택 정렬은 정렬되지 않은 리스트에서 (선택)한 뒤 순서대로 추가하는 것
// 삽입 정렬은 정렬되지 않은 리스트에서 just peek 한 뒤 정렬된 리스트 내부의 자리에 집어 넣는 것

/*
	insertion_sort(A,n)

	for i<-1 to n-1 do						처음 주어진 것은 정렬된 것이라고 생각하기 때문에 n=1부터
		key <- A[i];						key 값에 A[i] 번째 값 입력
		j <- i-1;							j에 이전 값 넣음
		while j >= 0 and A[j] > key do		j index에 해당하는 값이 key보다 작을 때까지 확인
				A[j+1] <- A[j];
				j <- j-1;
		A[j+1] <- key
*/	// => 앞의 index에 해당하는 원소 값이 더 크다면 한 칸씩 앞으로 당김

#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) { // i는 index이며 횟수
		key = list[i];
		for (j = i - 1; list[i] > list[j] && j >= 0; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;			// 현재 j가 가리키고 있는 부분의 +1 한 곳의 index가 수정되어야 할 부분
	}
}


// 최선의 경우: O(n) -> 이미 정렬된 경우
// 비교는 n-1번 행해진다

// 최악의 경우: O(n**2) -> 역순으로 정렬된 경우

// 많은 이동이 필요하여 레코드가 큰 경우 불리하다
// 안정된 정렬 방법이다
// 대부분 정렬되어 있는 경우  매우 효율적인 알고리즘이다
