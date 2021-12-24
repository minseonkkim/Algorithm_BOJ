#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, a, b, indegree[MAX], result[MAX];
	vector<int> v[MAX];
	queue<int> q;
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int sNum, s1, s2;
		cin >> sNum;
		cin >> s1;
		for(int i = 0; i < sNum - 1; i++){
			cin >> s2;
			v[s1].push_back(s2);
			indegree[s2]++;
			s1 = s2;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0) q.push(i);
	}
	
	for(int i = 1; i <= n; i++){
		if(q.empty()) {
			cout << 0 << endl;
			return 0;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		
		for(int j = 0; j < v[x].size(); j++){
			int y = v[x][j];
			if(--indegree[y] == 0) q.push(y);
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << result[i] << endl;
	}
	
	return 0;
}
