#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int adj[501][501];

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> adj[i][j];
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(adj[a][b] <= c) cout << "Enjoy other party" << '\n';
		else cout << "Stay here" << '\n';
		
	}
	return 0;
}
