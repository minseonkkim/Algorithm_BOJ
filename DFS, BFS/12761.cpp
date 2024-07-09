#include <iostream>
#include <queue>
using namespace std;

int a, b, n, m, cnt;
queue<int> q;
bool visited[100001];
int store[100001];

int main() {
	cin >> a >> b >> n >> m;

	int d[8] = { -1 , 1, -a, a, -b, b, a, b };
	
	q.push(n);
	visited[n] = true;
	store[n] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == m) {
			cout << store[m];
			break;
		}

		for (int i = 0; i < 6; i++) {
			int next = cur + d[i];

			if (next < 0 || next > 100000) continue;
			if (visited[next]) continue;

			visited[next] = true;
			store[next] = store[cur] + 1;
			q.push(next);
		}
		for (int i = 6; i < 8; i++) {
			int next = cur * d[i];

			if (next < 0 || next > 100000) continue;
			if (visited[next]) continue;

			visited[next] = true;
			store[next] = store[cur] + 1;
			q.push(next);
		}
	}
}
