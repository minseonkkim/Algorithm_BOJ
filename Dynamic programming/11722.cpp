#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	vector<int> dp(n, 1);
 
	for (int x = 0; x < n; x++) {
		cin >> arr[x];
	}
	int answer = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < y; x++) {
			if (arr[x] > arr[y]) {
				dp[y] = max(dp[y], dp[x] + 1);
			}
		}
		answer = max(answer, dp[y]);
	}
	cout << answer;
}
