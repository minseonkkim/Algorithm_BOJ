#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s1, s2;
	cin >> s1 >> s2;
	
	int s1_size = s1.length();
	int s2_size = s2.length();

	for(int i = 1; i <= s1_size; i++){
		for(int j = 1; j <= s2_size; j++){
			if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	cout << dp[s1_size][s2_size] << endl;
	return 0;
}
