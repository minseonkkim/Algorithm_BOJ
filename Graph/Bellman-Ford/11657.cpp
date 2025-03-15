#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<pair<int, int>, int>> edge;
long long dist[501];

void bellman(){
	dist[1] = 0;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < edge.size(); j++){
			int s = edge[j].first.first;
			int e = edge[j].first.second;
			int cost = edge[j].second;
			if(dist[s] == 1e18) continue;
			if(dist[e] > dist[s] + cost) dist[e] = dist[s] + cost;
		}
	}
	for(int j = 0; j < edge.size(); j++){
		int s = edge[j].first.first;
		int e = edge[j].first.second;
		int cost = edge[j].second;
		if(dist[s] == 1e18) continue;
		if(dist[e] > dist[s] + cost) {
			cout << -1;
			return;
		}
	}
	for(int i = 2; i <= n; i++){
		if(dist[i] == 1e18) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i <= 500; i++) dist[i] = 1e18;
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({{a, b}, c});
	}
	
	bellman();
	
	return 0;
}
