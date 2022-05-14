#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int dist[1001];
vector<pair<int, int>> v[100001];

void dijkstra(int start){
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({dist[start], start});
	
	while(!pq.empty()){
		int cur = pq.top().second;
		int distance = pq.top().first * -1;
		pq.pop();
		
		if(dist[cur] < distance) continue;
		
		for(int i = 0; i < v[cur].size(); i++){
			int next = v[cur][i].first;
			int nextDistance = distance + v[cur][i].second;
			
			if(nextDistance < dist[next]){
				dist[next] = nextDistance;
				pq.push({nextDistance * -1, next});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, start, end;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) dist[i] = INF;
	for(int i = 0; i < m; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({to, cost});
	}
	cin >> start >> end;
	
	dijkstra(start);
	
	cout << dist[end] << endl;
}
