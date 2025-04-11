#include <iostream>
#include <queue>
using namespace std;

int n, m;
queue<int> q[200001];
int cnt[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		for(int j = 0; j < num; j++){
			int sn;
			cin >> sn;
			q[sn].push(i);
		}
	}
	for(int i = 0; i < m; i++){
		int ms;
		cin >> ms;
		if(!q[ms].empty()){
			int cur = q[ms].front();
			cnt[cur]++;
			q[ms].pop();
		}
	}
	for(int i = 1; i <= n; i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
