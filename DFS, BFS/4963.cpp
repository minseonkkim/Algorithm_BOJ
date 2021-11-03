#include <iostream>
#include <queue>
using namespace std;

int map[51][51];
int w, h;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int a, int b) {
	map[a][b] = 0;

	queue<pair<int, int>> q;
	q.push(pair<int, int>(a, b));

	int cx, cy, ax, ay;
	while (!q.empty()) {
		cx = q.front().first;
		cy = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			ax = cx + dx[i];
			ay = cy + dy[i];

			if (ax >= 0 && ay >= 0 && ax < h && ay < w && map[ax][ay] == 1) {
				map[ax][ay] = 0;
				q.push(pair<int, int>(ax, ay));
			}
		}
	}
}

int main() {
	int cnt;
	cin >> w >> h;
	while (w != 0 && h != 0) {
		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;

		// map 초기화
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = 0;
			}
		}

		cin >> w >> h;
	}
	return 0;
}
