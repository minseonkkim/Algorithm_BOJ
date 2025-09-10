#include <iostream>
#include <cmath>
using namespace std;

int board[100001][4];
int maxdp[4];
int mindp[4];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			cin >> board[i][j];
		}
	}
	maxdp[1] = mindp[1] = board[1][1];
	maxdp[2] = mindp[2] = board[1][2];
	maxdp[3] = mindp[3] = board[1][3];
	
	for(int i = 2; i <= n; i++){
		int tmp = maxdp[2];
		maxdp[2] = board[i][2] + max(max(maxdp[1], maxdp[2]), maxdp[3]);
		maxdp[1] = board[i][1] + max(maxdp[1], tmp);
		maxdp[3] = board[i][3] + max(tmp, maxdp[3]);
		
		tmp = mindp[2];
		mindp[2] = board[i][2] + min(min(mindp[1], mindp[2]), mindp[3]);
		mindp[1] = board[i][1] + min(mindp[1], tmp);
		mindp[3] = board[i][3] + min(tmp, mindp[3]);
	}
	
	int maxscore = max(max(maxdp[1], maxdp[2]), maxdp[3]);
	int minscore = min(min(mindp[1], mindp[2]), mindp[3]);
	
	cout << maxscore << " " << minscore;
	return 0;
}
