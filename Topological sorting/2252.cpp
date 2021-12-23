#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int n, indegree[MAX];
vector<int> a[MAX];

void topologySort(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int result[MAX];
	queue<int> q;
	
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0) q.push(i);
	}
	
	for(int i = 1; i <= n; i++){
		int x = q.front();
		q.pop();
		result[i] = x;
		for(int i = 0; i < a[x].size(); i++){
			int y = a[x][i];
			if(--indegree[y] == 0){
				q.push(y);
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
		cout << result[i] << " ";
}

int main() {
	int m, x, y;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		a[x].push_back(y);
		indegree[y]++;
	}
	
	topologySort();
	return 0;
}
