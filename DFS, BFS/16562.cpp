#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
int cost[10001];
vector<int> frd[10001];

bool visited[10001];
int sum = 0;

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	
	int mincost = cost[start];
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		for(int i = 0; i < frd[cur].size(); i++){
			int next = frd[cur][i];
			if(!visited[next]) {
				mincost = min(mincost, cost[next]);
				visited[next] = true;
				q.push(next);
			}
		}
	}
	sum += mincost;
}

int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
	}
	for(int i = 0; i < m; i++){
		int v, w;
		cin >> v >> w;
		frd[v].push_back(w);
		frd[w].push_back(v);
	}
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]) bfs(i);
	}
	
	if(sum > k) cout << "Oh no";
	else cout << sum;
	return 0;
}
