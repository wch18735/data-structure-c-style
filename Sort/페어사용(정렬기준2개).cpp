#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<string, pair<int, int>> a,
			 pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		// 성적이 같으면 생일이 어린 것이 우선 순위
		// 어림 -> 이어 붙였을 때, 더 큰 것
		return a.second.second > b.second.second;
	}
	else { // 성적이 다르면 높은 것이 우선 순위
		return a.second.first > b.second.first;
	}
}

int main(void) {
	// 이름, 성적, 생년월일
	vector<pair<string,pair<int,int>>> v;

	v.push_back(pair<string, pair<int, int>>("원철황", pair<int, int>(95, 19960131)));
	v.push_back(pair<string, pair<int, int>>("이종근", pair<int, int>(98, 19930518)));
	v.push_back(pair<string, pair<int, int>>("김진형", pair<int, int>(95, 19930203)));
	v.push_back(pair<string, pair<int, int>>("전도현", pair<int, int>(90, 19921107)));
	v.push_back(pair<string, pair<int, int>>("박신학", pair<int, int>(88, 19900302)));


	// vector 의 시작과 끝까지 sort
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
		// second: pair 의 두 번째
	}
}