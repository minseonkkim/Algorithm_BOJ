#include <iostream>
using namespace std;

int n, m;
int info[21][2];
int dp[21][201];

int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> info[i][0] >> info[i][1];
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(j < info[i][0]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j - info[i][0]] + info[i][1], dp[i - 1][j]);
		}
	}
	
	cout << dp[m][n];
	
	return 0;
}
