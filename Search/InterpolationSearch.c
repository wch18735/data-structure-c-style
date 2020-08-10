// 사전이나 전화번호부를 탐색하는 방법
// 탐색키가 존재할 위치를 예측하여 탐색하는 방법: O(log(n))
// 보간탐색은 이진 탐색과 유사하나 리스트를 불균등 분할하여 탐색
// 비례식을 이용해 찾는다: 찾으려는 key 값과 처음, 끝의 key 값의 비율과 index의 비율을 집어넣어 찾음

int interpol_search(int key, int n)
{
	int low, high, j;
	low = 0;
	high = n - 1;
	while ((list[high] >= key) && (key > list[low])) {
		j = ((float)(key - list[low]) / (list[high] - list[low])		// 형변환 필요
			*(high - low)) + low;
		if (key > list[j]) low = j + 1;
		else if (key < list[j]) high = j - 1;
		else low = j;
	}
	if (list[low] == key) return(low); // 탐색성공
	else return -1; // 탐색실패
}
