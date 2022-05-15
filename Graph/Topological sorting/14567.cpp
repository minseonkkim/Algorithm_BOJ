#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, indegree[1001];
vector<int> a[1001];

void topologySort(){
	int result[1001];
	queue<int> q;
	
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
		result[i] = 1;
	}
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		for(int i = 0; i < a[cur].size(); i++){
			int next = a[cur][i];
			if(--indegree[next] == 0) {
				q.push(next);
				result[next] = max(result[next], result[cur] + 1);
			}
		}
	}
	
	for(int i = 1; i <= n; i++) 
		cout << result[i] << " ";
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		indegree[y]++;
	}
	topologySort();
	return 0;
}
