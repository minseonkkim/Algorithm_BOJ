#include <iostream>
#include <cmath>
using namespace std;

char board[1024][1024];

void func(int depth, int row, int col){
	if(depth == 0){
		board[row][col] = '*';
		return;
	} 
	func(depth - 1, row, col);
	func(depth - 1, row + pow(2, depth - 1), col);
	func(depth - 1, row, col + pow(2, depth - 1));
}

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < pow(2, n); i++){
		for(int j = 0; j < pow(2, n) - i; j++){
			board[i][j] = ' ';
		}
	}
	
	func(n, 0, 0);
	
	for(int i = 0; i < pow(2, n); i++){
		for(int j = 0; j < pow(2, n) - i; j++){
			cout << board[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}
