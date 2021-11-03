#include <iostream>
#include <queue>
using namespace std;

int main() {
	int c, n, m, num, tmp, cnt;
	cin >> c;

	for (int i = 0; i < c; i++) {
		cnt = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> num;
			q.push(pair<int, int>(j, num));
			pq.push(num);
		}
		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();

			if (pq.top() == val) {
				pq.pop();
				++cnt;
				if (idx == m) {
					cout << cnt << endl;
					break;
				}
			}
			else q.push(pair<int, int>(idx, val));
		}
	}
	return 0;
}
