#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> arr(n);
	vector<int> dp(n);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int answer = arr[0];
	dp[0] = arr[0];
	for(int i = 1; i < n; i++){
		dp[i] = arr[i];
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		answer = max(answer, dp[i]);
	}
	
	cout << answer << endl;
	return 0;
}
