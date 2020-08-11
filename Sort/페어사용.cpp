#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first > b.first;
}

int main(void) {
	vector<pair<int, string>> v;

	// int형을 기준으로 정렬이 이뤄짐
	// vector로 만들어진 List
	// vector.push_back -> Vector list에 추가하는 것
	v.push_back(pair<int, string>(90, "원철황"));
	v.push_back(pair<int, string>(85, "이진하"));
	v.push_back(pair<int, string>(82, "이종근"));
	v.push_back(pair<int, string>(98, "김진형"));
	v.push_back(pair<int, string>(79, "박신학"));
	
	// vector 의 시작과 끝까지 sort
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
		// second: pair 의 두 번째
	}
}