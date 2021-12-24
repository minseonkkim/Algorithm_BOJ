#include <iostream>
#include <vector>
using namespace std;

vector<int> map[1001];
bool visited[1001];
int cnt = 0;

void dfs(int a){
	visited[a] = true;
	
	for(int i = 0; i < map[a].size(); i++){
		int next = map[a][i];
		if(!visited[next])
			dfs(next);
	}
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
