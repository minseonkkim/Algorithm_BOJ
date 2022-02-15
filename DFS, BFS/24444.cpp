#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> e(100001);
int visited[100001];
int cnt = 1;

void bfs(int w){
	visited[w] = cnt++;
	queue<int> q;
	q.push(w);
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int i = 0; i < e[node].size(); i++){
			if(!visited[e[node][i]]){
				visited[e[node][i]] = cnt++;
				q.push(e[node][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, r, u, v;
	cin >> n >> m >> r;

	for(int i = 0; i < m; i++){
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++){
		sort(e[i].begin(), e[i].end());
	}
	
	bfs(r);
	
	for(int i = 1; i <= n; i++){
		cout << visited[i] << '\n';
	}
	return 0;
}
