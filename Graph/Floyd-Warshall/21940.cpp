#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int graph[201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) graph[i][j] == 0;
			else graph[i][j] = INF;
		}
	}
	
	for(int i = 0; i < m; i++){
		int a, b, t;
		cin >> a >> b >> t;
		graph[a][b] = t;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	
	int nn;
	cin >> nn;
	vector<int> v;
	
	for(int i = 0; i < nn; i++){
		int c;
		cin >> c;
		v.push_back(c);
	}
	
	int min = INF;
	vector<int> answer;
	for(int k = 1; k <= n; k++){
		int max = 0;
		bool flag = true;
		for(int i = 0; i < nn; i++){
			if((graph[v[i]][k] == INF) || (graph[k][v[i]] == INF)){
				flag = false;
				break;
			}
			if(graph[v[i]][k] + graph[k][v[i]] > max)
				max = graph[v[i]][k] + graph[k][v[i]];
		}
		if(flag){
			if(max < min) {
				min = max;
				answer.clear();
				answer.push_back(k);
			} else if(max == min) {
				answer.push_back(k);
			}
		}
	}

	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << " ";
	}
	
	return 0;
}
