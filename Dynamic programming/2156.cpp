#include <iostream>
#include <algorithm>
using namespace std;

int arr[10010];
int dp[10010];
int n;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for(int i = 3; i <= n; i++){
		dp[i] = max(max(dp[i - 1], dp[i - 2] + arr[i]), dp[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp[n] << endl;
	return 0;
}
