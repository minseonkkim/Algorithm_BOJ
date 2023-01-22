#include <iostream>
using namespace std;

int arr[301][301];
int dp[301][301];

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m ; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(arr[i][j] == 1){
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
			} else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	cout << dp[n][m] << endl;
	return 0;
}
