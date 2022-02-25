#include <iostream>
using namespace std;

int main() {
	int n, num;
	long long dp[1000001] = {0, 1, 2, 4};
	for(int j = 4; j <= 1000001; j++){
		dp[j] = ((dp[j - 1] + dp[j - 2])% 1000000009 + dp[j - 3]) % 1000000009;
	}
	
    cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		cout << dp[num] << endl;
	}
	return 0;
}
