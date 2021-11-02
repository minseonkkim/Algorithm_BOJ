#include <iostream>
#include <queue>
using namespace std;

// 상하좌우
int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

int m, n;
int map[51][51];

void bfs(int x, int y) {
	map[x][y] = 0;

	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));

	int cx, cy, ax, ay;
	while (!q.empty()) {
		cx = q.front().first;
		cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			ax = cx + dx[i];
			ay = cy + dy[i];

			if (ax >= 0 && ay >= 0 && ax < m && ay < n && map[ax][ay] == 1) {
				map[ax][ay] = 0;
				q.push(pair<int, int>(ax, ay));
			}
		}
	}
}

int main(){
	int t, k, x, y;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		int cnt = 0;

		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}
	return 0;
}
