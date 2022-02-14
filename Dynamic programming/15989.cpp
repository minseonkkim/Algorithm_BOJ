#include <iostream>
using namespace std;

int main() {
	long long dp[10001][4] = { 0, };
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][3] = 1;
	for(int i = 3; i <= 10000; i++){
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		if(i > 3) dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}
	
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}
	return 0;
}
