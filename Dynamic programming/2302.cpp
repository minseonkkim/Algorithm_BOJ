#include <iostream>
using namespace std;
 
int n, m;
int dp[41];
 
int main() {
	cin >> n >> m;
    dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= n; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int last = 0;
	int answer = 1;
	for(int i = 0; i < m; i++){
		int fixed;
		cin >> fixed;
		answer *= dp[fixed - last - 1];
		last = fixed;
	}
	answer *= dp[n - last];
	cout << answer;
	return 0;
}
