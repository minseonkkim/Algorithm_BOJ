#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, a, b;
int bridge[10001];
bool visited[10001];

void bfs(){
	queue<pair<int, int>> q;
	q.push({a, 0});
	visited[a] = true;
	
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cur == b){
			cout << cnt;
			return;
		}
		
		for(int i = cur + bridge[cur]; i <= n; i += bridge[cur]){
			if(!visited[i]){
				visited[i] = true;
				q.push({i, cnt + 1});
			}
		}
		for(int i = cur - bridge[cur]; i >= 1; i -= bridge[cur]){
			if(!visited[i]){
				visited[i] = true;
				q.push({i, cnt + 1});
			}
		}
	}
	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> bridge[i];
	}
	cin >> a >> b;
	bfs();
	return 0;
}
