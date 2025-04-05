#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[10001];
int dp[10001];

int main() {
	int t;
	cin >> t;
	for(int test_case = 1; test_case <= t; test_case++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> arr[i];
			dp[i] = 1;
		}
		int maxdp = 1;
		for(int i = 2; i <= n; i++){
			for(int j = 1; j < i; j++){
				if(arr[j] < arr[i]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if(dp[i] > maxdp) maxdp = dp[i];
		}
		int answer = (maxdp >= k) ? 1 : 0;
		cout << "Case #" << test_case << "\n" << answer << "\n";
	}
	return 0;
}
