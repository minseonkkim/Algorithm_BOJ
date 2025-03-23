#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int a, k;
bool visited[1000001];

void bfs(){
	queue<pair<int, int>> q;
	q.push({a, 0});
	visited[a] = true;
	
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cur == k){
			cout << cnt;
			return;
		}
		
		int next = cur + 1;
		if(next <= 1000000 && !visited[next]){
			visited[next] = true;
			q.push({next, cnt + 1});
		}
		
		next = cur * 2;
		if(next <= 1000000 && !visited[next]){
			visited[next] = true;
			q.push({next, cnt + 1});
		}
	}
}

int main() {
	cin >> a >> k;
	bfs();
	return 0;
}
