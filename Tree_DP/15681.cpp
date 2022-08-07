#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int dp[MAX];
vector<int> vec[MAX];
bool visited[MAX];

void dfs(int node, int parent){
	visited[node] = true;
	for(int i = 0; i < vec[node].size(); i++){
		int next = vec[node][i];
		if(!visited[next])
			dfs(next, node);
	}
	if(parent != -1){
		dp[parent] += dp[node];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, r, q;
	cin >> n >> r >> q;

	for(int i = 0; i < n + 1; i++)
		dp[i] = 1;
		
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	
	dfs(r, -1);
	
	for(int i = 0; i < q; i++){
		int u;
		cin >> u;
		cout << dp[u] << endl;
	}
	return 0;
}
