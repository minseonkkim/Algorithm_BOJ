#include <iostream>
using namespace std;

int main() {
	int h, w, ans = 0;
	string board[100];
	
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		cin >> board[i];
		int s = 0;
		for(int j = 0; j < w; j++){
			if(board[i][j] != '.'){
				s++;
				ans += 1;
			}
			if(s % 2 == 1 && board[i][j] == '.'){
				ans += 2;
			}
		}
	}
	cout << ans / 2 << endl;
	return 0;
}
