#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int M, N;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int arr[101][101];
int dist[101][101];

void dijkstra() {
    queue<pair<int, int>> pq;
	pq.push({ 0, 0 });
	dist[0][0] = 0;

	while (!pq.empty()) {
		int cy = pq.front().first;
		int cx = pq.front().second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
            
            if (!(ny >= 0 && ny < N && nx >= 0 && nx < M)) continue;

			if (arr[ny][nx] == 1) {
				if (dist[ny][nx] > dist[cy][cx] + 1) {
					dist[ny][nx] = dist[cy][cx] + 1;
					pq.push({ ny,nx });
				}
			}else if (arr[ny][nx] == 0) {
				if (dist[ny][nx] > dist[cy][cx]) {
					dist[ny][nx] = dist[cy][cx];
					pq.push({ ny,nx });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
			dist[i][j] = INF;
		}
	}

	dijkstra();
	printf("%d", dist[N - 1][M - 1]);
	return 0;
}
