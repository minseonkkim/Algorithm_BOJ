#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int map[1000][1000];
int dp[1000][1000];

int main() {
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	
  int answer = 0;
	for(int i = 0; i < n; i++) {
		if(map[0][i] == 0) {
            dp[0][i] = 1;
            answer = 1;
        } else dp[0][i] = 0;
	}
	for(int i = 1; i < m; i++){
		if(map[i][0] == 0) {
            dp[i][0] = 1;
            answer = 1;
        } else dp[i][0] = 0;
	}
	
	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(map[i][j] == 0){
				if(dp[i - 1][j - 1] != 0 && dp[i - 1][j] != 0 && dp[i][j - 1] != 0){
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
					if(dp[i][j] > answer) answer = dp[i][j];
				} else dp[i][j] = 1;
			} else dp[i][j] = 0;
		}
	}
	cout << answer;
	return 0;
}
