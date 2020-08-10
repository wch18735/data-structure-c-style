// 이진 탐색: 정렬된 배열의 중앙에 있는 값을 조사하여 찾고자 하는 항목이 
//			  왼쪽 또는 오른쪽 부분 배열에 있는지를 알아내어 탐색 범위를 반으로 줄여가며 탐색 진행
// 정렬된 배열을 가정한다

// ex) 10억 명 중에서 특정 이름 탐색
// 순차 탐색은 평균 5억번 필요한데 이진탐색은 30번이면 된다

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 10000000L
int list[MAX_ELEMENTS];
int count;	// 수행횟수

			//
			// 이진 탐색
			//
int binsearch(int list[], int n, int searchnum)
{
	int left = 0;
	int right = n - 1;
	int middle;

	count = 0;
	while (left <= right) {		// 아직 숫자들이 남아 있으면
		count++;
		middle = (left + right) / 2;
		if (searchnum == list[middle]) {
			return middle;
		}
		else if (searchnum < list[middle]) {
			right = middle - 1;
		}
		else {
			left = middle + 1; break;
		}
	}
	return -1;		// 발견되지 않음 
}

//
// 순차 탐색
//
int seqsearch(int list[], int n, int searchnum)
{
	int i;

	count = 0;
	for (i = 0; i<n; i++) {
		count++;
		if (searchnum == list[i])
			return i;
	}
	return -1;		// 발견되지 않음 
}

int search_binary2(int key, int low, int high)
{
	int middle;
	while (low <= high) { // 아직 숫자들이 남아 있으면
		middle = (low + high) / 2;
		if (key == list[middle]) return middle; // 탐색 성공
		else if (key > list[middle]) low = middle + 1; // 왼쪽 부분리스트 탐색
		else high = middle - 1; // 오른쪽 부분리스트 탐색
	}
	return -1; // 탐색 실패
}

int main()
{
	int i;
	int search_number;
	int return_value;
	clock_t start, finish;
	clock_t  duration;

	for (i = 0; i<MAX_ELEMENTS; i++)
		list[i] = i;

	printf("숫자를 입력하시요.\n", &search_number);
	scanf("%d", &search_number);

	start = clock();
	return_value = seqsearch(list, MAX_ELEMENTS, search_number);
	finish = clock();

	duration = finish - start;
	printf("%d milliseconds\n", duration);
	printf("문자의 수행횟수=%d\n ", count);

	start = clock();
	return_value = binsearch(list, MAX_ELEMENTS, search_number);
	finish = clock();

	duration = finish - start;
	printf("%d milliseconds\n", duration);
	printf("문자의 수행횟수=%d\n ", count);

	if (return_value == -1) {
		printf("숫자가 발견되지 않았읍니다.\n", &search_number);
	}
	else {
		printf("숫자가 위치 %d에서 발견되었읍니다.\n", return_value);
	}
	return 0;
}

