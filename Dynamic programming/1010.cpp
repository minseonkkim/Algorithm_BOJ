#include <iostream>
using namespace std;

int main() {
	int t, n, m;
	cin >> t;
	
	int dp[31][31] = {0, };
	for(int i = 1; i <= 30; i++){
		for(int j = 1; j <= 30; j++){
			if(i == 1){
				dp[i][j] = j;
			}
			else if(i == j){
				dp[i][j] = 1;
			}
			else{
				for(int k = i - 1; k < j; k++){
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
	}
	
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		cout << dp[n][m] << endl;
	}
	return 0;
}
