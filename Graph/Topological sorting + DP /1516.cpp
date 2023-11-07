#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int cost[501];
vector<int> edge[501];
int indegree[501];
int dp[501];

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
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
		int input;
		cin >> input;
		while(input != -1){
			indegree[i]++;
			edge[input].push_back(i);
			cin >> input;
		}
	}
	
	topologicalSort();
	
	for(int i = 1; i <= n; i++){
		cout << dp[i] << '\n';
	}
	return 0;
}
