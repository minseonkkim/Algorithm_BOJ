#include <iostream>
using namespace std;

int main() {
	int dp[31][31];
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(j == 1 || j == i) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}
