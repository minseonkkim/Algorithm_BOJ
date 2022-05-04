#include <iostream>
#include <algorithm>
#define INF 987654321;
using namespace std;

int graph[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}
	
	for(int i = 0; i < n - 1; i++){
		int from, to, dis;
		cin >> from >> to >> dis;
		graph[from][to] = dis;
		graph[to][from] = dis;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		cout << graph[a][b] << endl;
	}
	
	return 0;
}
