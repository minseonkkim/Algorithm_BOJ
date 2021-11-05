#include <iostream>
using namespace std;

int main() {
	int n, k;
	int w[101] = { 0, };
	int v[101] = { 0, };
	int dp[101][100001] = { 0, };
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (w[i] <= j) {
				dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}
