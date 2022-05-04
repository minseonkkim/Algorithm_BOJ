#include <iostream>
#include <vector>
#include <algorithm>
#define INF 98765421
using namespace std;

int n, m;
int graph[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}
	
	for(int i = 0; i < m; i++){
		int from, to, dis;
		cin >> from >> to >> dis;
		graph[from][to] = min(graph[from][to], dis);
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(graph[i][j] == INF) cout << 0 << " ";
			else cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
