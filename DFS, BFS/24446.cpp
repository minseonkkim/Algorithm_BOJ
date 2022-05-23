#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, r;
vector<int> arr[100001];
bool visited[100001];
int dist[100001];
int cnt;

void bfs(int w){
	visited[w] = true;
	queue<int> q;
	q.push(w);
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		cnt++;
		
		for(int i = 0; i < arr[cur].size(); i++){
			if(!visited[arr[cur][i]]){
				visited[arr[cur][i]] = true;
				q.push(arr[cur][i]);
				dist[arr[cur][i]] = dist[cur] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> r;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	bfs(r);
	
	for(int i = 1; i <= n; i++){
		if(dist[i] == 0 && i != r){
			cout << -1 << '\n';
			continue;
		}
		cout << dist[i] << '\n';
	}
	return 0;
}
