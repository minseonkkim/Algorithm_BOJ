#include <iostream>
using namespace std;

int importance[10001];
int studytime[1001];
int dp[1001][10001];

int main() {
	int N, K;
	cin >> N >> K;
	for(int i = 1; i <= K; i++){
		int a, b;
		cin >> importance[i] >> studytime[i];
	}
	
	dp[0][0] = 0;
	for(int i = 1; i <= K; i++){
		for(int j = 1; j <= N; j++){
			if(studytime[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - studytime[i]] + importance[i]);
		}
	}
	cout << dp[K][N];
	return 0;
}
