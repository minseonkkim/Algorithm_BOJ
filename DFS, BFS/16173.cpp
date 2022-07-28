#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[3][3];

string bfs(){
	queue<pair<int, int>> q;
	q.push({0, 0});
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		int step = arr[x][y];
		q.pop();
		
		if(step == -1) return "HaruHaru";
		if(step == 0) continue;
		
		if(x + step < n) q.push({x + step, y});
		if(y + step < n) q.push({x, y + step});
	}
	return "Hing";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	cout << bfs() << endl;
	return 0;
}
