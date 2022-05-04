#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m, r;
int item[101];
int graph[101][101];
int answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> r;
	for(int i = 1; i <= n; i++) cin >> item[i];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}
	
	// 간선 입력
	for(int i = 0; i < r; i++){
		int from, to, dis;
		cin >> from >> to >> dis;
		graph[from][to] = dis;
		graph[to][from] = dis;
	}
	
	// 플로이드 와샬
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}
	
	// 정점별로 아이템 수색
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			if(graph[i][j] <= m){
				cnt += item[j];
			}
		}
		answer = max(answer, cnt);
	}
	cout << answer << endl;
	return 0;
}
