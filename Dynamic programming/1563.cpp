#include <iostream>
#include <vector>
using namespace std;

const int divval = 1000000;
int dp[1001][2][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
	
	for(int i = 2; i <= n; i++){
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % divval;
		dp[i][0][1] = (dp[i - 1][0][0]) % divval;
		dp[i][0][2] = (dp[i - 1][0][1]) % divval;
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % divval;
		dp[i][1][1] = (dp[i - 1][1][0]) % divval;
		dp[i][1][2] = (dp[i - 1][1][1]) % divval;
	}
	
	int ans = (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % divval;
	
	cout << ans << endl;
	return 0;
}
