#include <iostream>
#include <stack>
using namespace std;

int n;
stack<pair<int, int>> st;
int perfect_score, remaining_time;
int sum;

int main() {
	cin >> n;
	int command, a, t;
	for (int i = 1; i <= n; i++) {
		cin >> command;
		if (command == 1) {
			cin >> a >> t;
			st.push({ a, t });
		}
		if (!st.empty()) {
			st.top().second--;
			if (st.top().second == 0) {
				sum += st.top().first;
				st.pop();
			}
		}
	}
	cout << sum;
}
