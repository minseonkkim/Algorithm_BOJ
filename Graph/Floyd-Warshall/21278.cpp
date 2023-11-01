#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, m;
int dist[101][101];
int building1, building2;
int minsum = 987654321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for(int i = 1; i <= n - 1; i++){
		for(int j = i + 1; j <= n; j++){
			int sum = 0;
			for(int p = 1; p <= n; p++){
                sum += min(dist[p][i] * 2, dist[p][j] * 2);
			}
			if(sum < minsum){
				minsum = sum;
				building1 = i;
				building2 = j;
			}
		}
	}
	cout << building1 << " " << building2 << " " << minsum;
	return 0;
}
