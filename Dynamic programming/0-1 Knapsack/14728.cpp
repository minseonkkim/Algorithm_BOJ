#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][10001];
int studytime[101];
int score[101];

int main() {
	int N, T;
	cin >> N >> T;
	for(int i = 1; i <= N; i++){
		cin >> studytime[i] >> score[i];
	}
	dp[0][0] = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= T; j++){
			if(studytime[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - studytime[i]] + score[i]);
		}
	}
	cout << dp[N][T];
	return 0;
}
