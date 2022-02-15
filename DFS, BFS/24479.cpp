#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> e(100001);
int visited[100001] = {0, };
int cnt = 1;

void dfs(int w){
	visited[w] = cnt++;
	for(int i = 0; i < e[w].size(); i++){
		if(!visited[e[w][i]]) dfs(e[w][i]);
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
	
	dfs(r);
	
	for(int i = 1; i <= n; i++){
		cout << visited[i] << '\n';
	}
	return 0;
}
