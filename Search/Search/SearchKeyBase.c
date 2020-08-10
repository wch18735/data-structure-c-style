// 탐색키 (search key)
// 항목과 항목을 구별해주는 키(key)
// 탐색을 위하여 사용되는 자료 구조
// 배열, 연결리스트, 트리, 그래프 등
// 탐색: 어떠한 자료 구조에서 원하는 값을 찾아내는 과정

// 순차 탐색 (Sequential search)
// 탐색 방법 중에서 가장 간단하고 직접적인 탐색 방법
// 정렬되지 않은 배열을 처음부터 마지막까지 하나씩 검사하는 방법
// 평균 비교 횟수
// 탐생성공: (n+1)/2 번 비교
// 탐색실패: n번 비교
// 시간복잡도: O(n)

int seq_search(int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++)
		if (list[i] == key)
			return i;	// 탐색 성공
	return -1;			// 탐색 실패
}

int seq_search2(int key, int low, int high) {
	int i;
	list[high + 1] = key;			// 키 값을 찾으면 종료
	for (i = low; list[i] != key; i++)
		;
	if (i == (high + 1)) return -1;	// 탐색 실패
	else return i;					// 탐색 성공
} // 탈출문 비교 1번, i랑 key 값이랑 비교였는데 i를 key의 index랑 비교하면서 한 번에 보냄

