#include <iostream>
#include <vector>
#include <queue>
#define INF 1e18
using namespace std;

int n, m;
bool visible[100000];
vector<pair<int, int>> edge[100000];
long long dist[100000];

void dijkstra(){
	dist[0] = 0;
	priority_queue<pair<long long, int>> pq;
	pq.push({0, 0});
	
	while(!pq.empty()){
		int cur = pq.top().second;
		long long dis = -pq.top().first;
		pq.pop();
		
		if(dist[cur] < dis) continue;
		
		for(int i = 0; i < edge[cur].size(); i++){
			int next = edge[cur][i].first;
			long long ndis = dis + edge[cur][i].second;
			
			if(next != n - 1 && visible[next] == 1) continue;
			if(ndis >= dist[next]) continue;
			
			dist[next] = ndis;
			pq.push({-ndis, next});
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> visible[i];
		dist[i] = INF;
	}
	for(int i = 0; i < m; i++){
		int a, b, t;
		cin >> a >> b >> t;
		edge[a].push_back({b, t});
		edge[b].push_back({a, t});
	}
	
	dijkstra();
	
	if(dist[n - 1] == INF) cout << -1;
	else cout << dist[n - 1];
	return 0;
}
