#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, a, b, indegree[MAX];
	vector<int> v[MAX];
	priority_queue<int, vector<int>, greater<int>> q;
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0) q.push(i);
	}
	
	for(int i = 1; i <= n; i++){
		int x = q.top();
		q.pop();
		
		cout << x << " ";
		
		for(int j = 0; j < v[x].size(); j++){
			int y = v[x][j];
			if(--indegree[y] == 0) q.push(y);
		}
	}
	
	return 0;
}
