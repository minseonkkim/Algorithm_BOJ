#include <iostream>
#include <queue>
using namespace std;

int updown[101];
bool visited[101];

void bfs(){
	queue<pair<int, int>> q;
	
	if(updown[1]){
		q.push({updown[1], 0});
		visited[updown[1]] = true;
	} else{
		q.push({1, 0});
	}
	visited[1] = true;
	
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cur == 100){
			cout << cnt;
			break;
		}
		
		for(int i = 1; i <= 6; i++){
			int next = cur + i;
			
			if(!visited[next]){
				if(updown[next]){
					q.push({updown[next], cnt + 1});
					visited[updown[next]] = true;
				} else{
					q.push({next, cnt + 1});
				}
				visited[next] = true;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n + m; i++){
		int a, b;
		cin >> a >> b;
		updown[a] = b;
	}
	bfs();
	return 0;
}
