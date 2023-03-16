#include <iostream>
using namespace std;

int parent[10001];
bool visited[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	for(int j = 0; j < t; j++){
		int n;
		cin >> n;
		// 초기화
		for(int i = 1; i <= n; i++){
			visited[i] = false;
			parent[i] = i;
		}
		// 간선 정보 입력
		for(int i = 0; i < n - 1; i++){
			int a, b;
			cin >> a >> b;
			parent[b] = a;
		}
		// 공통 조상 찾기
		int u, v;
		cin >> u >> v;
		visited[u] = true;
		while(u != parent[u]){
			u = parent[u];
			visited[u] = true;
		}
		while(true){
			if(visited[v]){
				cout << v << endl;
				break;
			}
			v = parent[v];
		}
	}
	return 0;
}
