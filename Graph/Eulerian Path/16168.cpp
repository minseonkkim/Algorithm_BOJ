#include <iostream>
#include <vector>
using namespace std;

int v, e;
vector<int> adj[3001];
int degree[3001];
bool visited[3001];

void dfs(int a){
	visited[a] = true;
	
	for(int i = 0; i < adj[a].size(); i++){
		int n = adj[a][i];
		if(!visited[n])
			dfs(n);
	}
}

int dfsAll(){
	int cnt = 0;
	for(int i = 1; i <= v; i++){
		if(!visited[i]){
			dfs(i);
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> v >> e;
	for(int i = 0; i < e; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	
	int component = dfsAll();
	if(component > 1){
		cout << "NO" << endl;
		return 0;
	}
	
	int cnt = 0;
	for(int i = 1; i <= v; i++){
		if(degree[i] % 2 != 0){
			cnt++;
		}
	}
	if(cnt == 0 || cnt == 2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
