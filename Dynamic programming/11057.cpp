#include <iostream>
using namespace std;

int n;
int dp[1001][10];

int main() {
	cin >> n;
	for(int i = 0; i <= 9; i++){
		dp[1][i] = 1;
	}
	for(int i = 2; i <= n; i++){
		dp[i][0] = 1;
		for(int j = 1; j <= 9; j++){
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	int cnt = 0;
	for(int i = 0; i <= 9; i++){
		cnt += dp[n][i];
	}
	cout << cnt % 10007;
	
	return 0;
}
