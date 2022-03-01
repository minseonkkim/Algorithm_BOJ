#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	stack <pair<int, int>> s;
	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;

		while (!s.empty()) {
			if (s.top().second > num) {
				cout << s.top().first << " ";
				break;
			}
			
			s.pop();
		}

		if (s.empty()) {
			cout << 0 << " ";
		}

		s.push({ i + 1, num });
	}

	return 0;
}
