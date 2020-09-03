#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	string query;
	int num;
	deque<int> myStack;

	for (int i = 0; i < n; i++) {
		cin >> query;
		
		// push
		if (query == "push") {
			cin >> num;
			myStack.push_back(num);
		}
		else if (query == "pop") {
			if (myStack.empty()) cout << -1 << '\n';
			else {
				cout << myStack.back() << '\n';
				myStack.pop_back();
			}
		}
		else if (query == "size") {
			cout << (int)myStack.size() << '\n';
		}
		else if (query == "empty") {
			if (myStack.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (query == "top") {
			if (myStack.empty()) cout << -1 << '\n';
			else {
				cout << myStack.back() << '\n';
			}
		}
	}

	return 0;
}