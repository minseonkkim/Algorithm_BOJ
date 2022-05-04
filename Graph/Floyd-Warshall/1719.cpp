#include <iostream>
#define INF 987654321
using namespace std;

int n, m;
int graph[201][201];
int answer[201][201];

int main() {
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
		graph[from][to] = dis;
		graph[to][from] = dis;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			answer[i][j] = j;
		}
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(graph[i][k] + graph[k][j] < graph[i][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
					answer[i][j] = answer[i][k];
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) cout << "-" << " ";
			else cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
