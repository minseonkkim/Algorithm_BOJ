#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[5001][5001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	string s, r_s;
	cin >> s;
	r_s = s;
	reverse(r_s.begin(), r_s.end());
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(s[i - 1] == r_s[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	cout << n - dp[n][n] << endl;
	
	return 0;
}
