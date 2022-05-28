#include <iostream>
using namespace std;

long long dp[1010][1010];
const int mod = 1000000007;

int main() {
	dp[1][1] = 1;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i * j != 1) 
				dp[i][j] = (dp[i][j - 1] % mod + dp[i - 1][j] % mod + dp[i - 1][j - 1] % mod) % mod;
		}
	}
	cout << dp[n][m] % mod << endl;
	return 0;
}
