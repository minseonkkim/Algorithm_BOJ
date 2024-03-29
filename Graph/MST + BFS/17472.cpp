#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[10][10];
int parent[7];
vector<pair<int, pair<int, int>>> bridge;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y, int num) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	map[x][y] = num;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] != -1) continue;
			
			map[nx][ny] = num;
			q.push({ nx, ny });
		}
	}
}


void connection(int x, int y, int dir) {
	int tmp = map[x][y];
	int nx = x;
	int ny = y;
	int length = 0;
	while (true) {
		nx += dx[dir];
		ny += dy[dir];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == tmp) return;
		if (map[nx][ny] == 0) {
			length++;
		}
		else {
			if (length >= 2) {
				bridge.push_back({ length, { tmp, map[nx][ny]} });
			}
			return;
		}
	}
}

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}
	}

	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1) {
				bfs(i, j, num);
				num++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				if (map[i][j] != 0) connection(i, j, k);
			}
		}
	}

	sort(bridge.begin(), bridge.end());

	for (int i = 0; i < 7; i++)
		parent[i] = i;

	int answer = 0;
	for (int i = 0; i < bridge.size(); i++) {
		if (!findParent(bridge[i].second.first, bridge[i].second.second)) {
			answer += bridge[i].first;
			unionParent(bridge[i].second.first, bridge[i].second.second);
		}
	}

	int p = getParent(1);
	for (int i = 2; i < num; i++) {
		if (p != getParent(i)) {
			answer = -1;
		}
	}
	cout << answer;
}
