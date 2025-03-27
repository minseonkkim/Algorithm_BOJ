#include <iostream>
using namespace std;

int n;
long long map[100][100];
long long dp[100][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(dp[i][j] == 0) continue;
			if(i == n - 1 && j == n - 1) break;
			if(i + map[i][j] < n) dp[i + map[i][j]][j] += dp[i][j];
			if(j + map[i][j] < n) dp[i][j + map[i][j]] += dp[i][j];
 		}
	}
	cout << dp[n - 1][n - 1];
	return 0;
}
