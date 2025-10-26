#include <iostream>
using namespace std;

int dp[21][100];
int mins[21];
int pls[21];

int main() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> mins[i];
	for(int i = 1; i <= N; i++) cin >> pls[i];
	dp[0][0] = 0;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= 99; j++){
			if(mins[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - mins[i]] + pls[i]);
		}
	}
	cout << dp[N][99];
	return 0;
}
