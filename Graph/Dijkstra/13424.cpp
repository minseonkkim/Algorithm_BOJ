#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<pair<int, int>> edge[101];
int dist[101][101];

void init(){
	for(int i = 1; i <= 100; i++) edge[i].clear();
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			dist[i][j] = INF;
		}
	}
}

void dijkstra(int start){
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	dist[start][start] = 0;
	
	while(!pq.empty()){
		int cur = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();
		
		if(dist[start][cur] < dis) continue;
		
		for(int i = 0; i < edge[cur].size(); i++){
			int next = edge[cur][i].first;
			int ndis = dis + edge[cur][i].second;
			
			if(dist[start][next] <= ndis) continue;
			
			pq.push({-ndis, next});
			dist[start][next] = ndis;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for(int test_case = 0; test_case < t; test_case++){
		init();
		
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			edge[a].push_back({b, c});
			edge[b].push_back({a, c});
		}
		
		int k;
		cin >> k;
		vector<int> f;
		for(int i = 0; i < k; i++){
			int start;
			cin >> start;
			f.push_back(start);
			dijkstra(start);
		}
		int min = INF;
		int answer = 0;
		for(int i = 1; i <= n; i++){
			int sum = 0;
			for(int j = 0; j < f.size(); j++){
				if(f[j] == i) continue;
				sum += dist[f[j]][i];
			}
			if(sum < min) {
				min = sum;
				answer = i;
			}
		}
		cout << answer << '\n';
	}
	return 0;
}
