#include <iostream>
#include <queue>
using namespace std;

int n, m, answer;
int arr[101];

void bfs(){
	queue<pair<pair<int, int>, int>> q;
	q.push({{0, 1}, 0});
	
	while(!q.empty()){
		int idx = q.front().first.first;
		int size = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if(size > answer) answer = size;
		
		if(cnt == m || idx == n){
			continue;
		}
		
		int nidx = idx + 1;
		q.push({{nidx, size + arr[nidx]}, cnt + 1});
		
		nidx = idx + 2;
		q.push({{nidx, size / 2 + arr[nidx]}, cnt + 1});
	}
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	bfs();
	cout << answer;
	return 0;
}
