#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, cnt;
int arr[101][101];
int fixedarr[101][101];
bool visited[101][101];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	visited[a][b] = true;
	q.push({ a, b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;

			if (!visited[nx][ny] && fixedarr[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (max < arr[i][j]) max = arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= max; i++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (arr[x][y] < i) fixedarr[x][y] = 0;
				else fixedarr[x][y] = 1;
			}
		}

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (fixedarr[x][y] == 1 && !visited[x][y]) {
					cnt++;
					bfs(x, y);
				}
			}
		}
		if (ans < cnt) ans = cnt;
		
		memset(visited, false, sizeof(visited));
		memset(fixedarr, 0, sizeof(fixedarr));
		cnt = 0;
	}
	cout << ans;
	return 0;
}
