#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr(1001, 0);
vector<int> dp(1001, 1);
vector<int> r_dp(1001, 1);

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int y = 0; y < n; y++){
		for(int x = 0; x < y; x++){
			if(arr[x] < arr[y])
				dp[y] = max(dp[y], dp[x] + 1);
		}
	}
	for(int y = n - 1; y >= 0; y--){
		for(int x = n - 1; x >= y; x--){
			if(arr[x] < arr[y])
				r_dp[y] = max(r_dp[y], r_dp[x] + 1);
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(dp[i] + r_dp[i] - 1, ans);
	}
	cout << ans << endl;
	return 0;
}
