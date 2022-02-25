#include <iostream>
using namespace std;

int main() {
	int n, num;
	long long dp[1000001] = {0, 1, 2, 4};
	for(int i = 4; i <= 1000001; i++){
		dp[i] = ((dp[i - 1] + dp[i - 2])% 1000000009 + dp[i - 3]) % 1000000009;
	}
	
    cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		cout << dp[num] << endl;
	}
	return 0;
}
