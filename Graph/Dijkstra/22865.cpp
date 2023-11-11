#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int house[3];
int dist[3][100001];
vector<pair<int, int>> edge[100001];

void dijkstra(int x, int s){
	priority_queue<pair<int, int>> pq;
	dist[x][s] = 0;
	pq.push({0, s});
	
	while(!pq.empty()){
		int curdis = -pq.top().first;
		int curx = pq.top().second;
		pq.pop();
		
		if(dist[x][curx] < curdis) continue;
		
		for(int i = 0; i < edge[curx].size(); i++){
			int nextdis = edge[curx][i].second;
			int nextx = edge[curx][i].first;
			if(dist[x][nextx] > curdis + nextdis){
				dist[x][nextx] = curdis + nextdis;
				pq.push({-dist[x][nextx], nextx});
			}
		}
	}
	
}

int main() {
	cin >> n;
	for(int i = 0; i < 3; i++){
		cin >> house[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		int d, e, l;
		cin >> d >> e >> l;
		edge[d].push_back({e, l});
		edge[e].push_back({d, l});
	}
	for(int i = 0; i < 3; i++){
		for(int j = 1; j <= n; j++){
			dist[i][j] = 987654321;
		}
	}
	
	for(int i = 0; i < 3; i++){
		dijkstra(i, house[i]);
	}
	
	int answer = 0;
	int maxdis = -1;
	for(int i = 1; i <= n; i++){
		if(house[0] == i || house[1] == i || house[2] == i) continue;
		
		int mindis = min(dist[0][i], min(dist[1][i], dist[2][i]));
		if(mindis > maxdis){
			maxdis = mindis;
			answer = i;
		}
	}
	cout << answer;
	return 0;
}
