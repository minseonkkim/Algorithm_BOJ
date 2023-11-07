#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, w;
int cost[1001];
vector<int> edge[1001];
int indegree[1001];
int dp[1001];

void topologicalSort(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0){
			q.push(i);
			dp[i] = cost[i];
		}
	}
	
	while(!q.empty()){
		int c = q.front();
		q.pop();
		for(int i = 0; i < edge[c].size(); i++){
			int n = edge[c][i];
			if(--indegree[n] == 0){
				q.push(n);
			}
			dp[n] = max(dp[n], cost[n] + dp[c]);
		}
	}
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> cost[i];
			
			indegree[i] = 0;
			dp[i] = 0;
			edge[i].clear();
		}
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			indegree[y]++;
			edge[x].push_back(y);
		}
		cin >> w;
		
		topologicalSort();
		
		cout << dp[w] << '\n';
	}
	return 0;
}
