#include <iostream>
#include <vector>
#include <queue>
#define INF 1e15
using namespace std;

int n, m, k;
long long dist[10001][21];
vector<pair<int, int>> edge[50001];

void dijkstra() {
	dist[1][0] = 0;
	priority_queue<pair<long long, pair<int, int>>> pq;
	pq.push({ 0, {1, 0} });

	while (!pq.empty()) {
		int cur = pq.top().second.first;
		int cnt = pq.top().second.second;
		long long dis = -pq.top().first;
		pq.pop();

		if (dist[cur][cnt] < dis) continue;

		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			long long next_dis = dis + edge[cur][i].second;

			// 포장X
			if (dist[next][cnt] > next_dis) {
				dist[next][cnt] = next_dis;
				pq.push({ -next_dis, {next, cnt} });
			}

			// 포장O
			if (dist[next][cnt + 1] > dis && cnt + 1 <= k) {
				dist[next][cnt + 1] = dis;
				pq.push({ -dis, {next, cnt + 1} });
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}

	dijkstra();

	long long ans = INF;
	for (int i = 0; i <= k; i++) {
		if (dist[n][i] < ans) ans = dist[n][i];
	}
	cout << ans;
}
