#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, n;
	cin >> t;
	
	long long dp[101] = {0, };
	dp[1] = 1; dp[2] = 1; dp[3] = 1;
	dp[4] = 2; dp[5] = 2;
	
	for(int i = 6; i <= 100; i++){
		dp[i] = dp[i - 1] + dp[i - 5];
	}	
	 
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}
