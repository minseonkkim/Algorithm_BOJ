#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 100001
#define INF 1e11
using namespace std;

int n, m, x, z, p;
long long dist[2][MAX];
vector<pair<int, long long>> edge[MAX];
long long answer = INF * 2;

void dijkstra(int idx, int start) {
	priority_queue<pair<long long, int>> pq;
	pq.push({ 0, start });
	dist[idx][start] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		long long dis = -pq.top().first;
		pq.pop();

		if (dis > dist[idx][cur]) continue;

		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			long long next_dis = edge[cur][i].second;
			
			if (next_dis + dis < dist[idx][next]){
				dist[idx][next] = next_dis + dis;
				pq.push({ -dist[idx][next], next });
			}
		}		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dist[0][i] = INF;
		dist[1][i] = INF;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}

	cin >> x >> z;

	dijkstra(0, x);
	dijkstra(1, z);
	
	cin >> p;
	for (int i = 0; i < p; i++) {
		int y;
		cin >> y;
		if (dist[0][y] == INF || dist[1][y] == INF) continue;
		answer = min(dist[0][y] + dist[1][y], answer);
	}
	if (answer == INF * 2) cout << -1;
	else cout << answer;
}
