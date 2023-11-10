#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int, int>> blank;
bool finish = false;

bool check(int x, int y){
	for(int i = 0; i < 9; i++){
		if(i != y && sudoku[x][y] == sudoku[x][i]) return false;
		if(i != x && sudoku[x][y] == sudoku[i][y]) return false;
	}
	
	int sx = (x / 3) * 3;
	int sy = (y / 3) * 3;
	for(int i = sx; i < sx + 3; i++){
		for(int j = sy; j < sy + 3; j++){
			if(i == x && j == y) continue;
			if(sudoku[i][j] == sudoku[x][y]) return false;
		}
	}
	
	return true;
}

void dfs(int n){
	if(n == blank.size()){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cout << sudoku[i][j] << " ";
			}
			cout << '\n';
		}
		finish = true;
		return;
	}
	
	int x = blank[n].first;
	int y = blank[n].second;
	
	for(int i = 1; i <= 9; i++){
		sudoku[x][y] = i;
		if(check(x, y)){
			dfs(n + 1);
		} 
		if(finish) return;
	}
	sudoku[x][y] = 0;
}

int main() {
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> sudoku[i][j];
			if(sudoku[i][j] == 0) blank.push_back({i, j});
		}
	}
	dfs(0);
	return 0;
}
