#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001
using namespace std;

int n, result = 0;
int delay[MAX];
int cache[MAX];
int inDegree[MAX];
vector<int> v[MAX];

void topologySort(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(inDegree[i] == 0) q.push(i);
		cache[i] = delay[i];
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int j = 0; j < v[x].size(); j++){
			int y = v[x][j];
			if(--inDegree[y] == 0){
				q.push(y);
			}
			cache[y] = max(cache[y], cache[x] + delay[y]);
		}
	}
	for(int i = 1; i <= n; i++){
		result = max(result, cache[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		int t, num;
		cin >> t >> num;
		
		delay[i] = t;

		for(int j = 0; j < num; j++){
			int x;
			cin >> x;
			v[x].push_back(i);
			inDegree[i]++;
		}
	}
	
	topologySort();
	
	cout << result << endl;
	return 0;
}
