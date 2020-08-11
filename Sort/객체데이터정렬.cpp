#include <iostream>
#include <string>
#include <algorithm> // 대표적인 STL

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) { // 생성자
		this->name = name;
		this->score = score;
	}
};

// 정렬 기준은 "점수가 작은 순서"
bool compare(Student a, Student b) { 
	return a.score > b.score;
}

int main(void) {
	Student students[] = {
		Student(string::basic_string("원철황"),90),
		Student(string::basic_string("이종근"),93),
		Student(string::basic_string("전도현"),97),
		Student(string::basic_string("김진형"),87),
		Student(string::basic_string("양혁진"),92)
	};

	sort(students, students + 5, compare);

	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}
