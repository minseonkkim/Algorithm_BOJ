#include <iostream>
#include <algorithm>
using namespace std;

int dp[16][16];
int n, cnt1 = 0, cnt2 = 0;

int matrix_path(int i, int j){
	if(i == 0 || j == 0) {
		cnt1++;
		return 0;
	}
	else return dp[i][j] + max(matrix_path(i - 1, j), matrix_path(i, j - 1));
}

int main(){
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> dp[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cnt2++;
		}
	}
	matrix_path(n, n);
	
	cout << cnt1 << endl;
	cout << cnt2 << endl;
	return 0;
}
