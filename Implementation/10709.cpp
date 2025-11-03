#include <iostream>
using namespace std;
 
int h, w;
char map[101][101];
int answer[101][101];
 
int main() {
	cin >> h >> w;
	for(int i = 1; i <= h; i++){
		string str;
		cin >> str;
		for(int j = 1; j <= w; j++){
			map[i][j] = str[j - 1];
		}
	}
	for(int i = 1; i <= h; i++){
		bool find = false;
		for(int j = 1; j <= w; j++){
			if(map[i][j] == 'c'){
				find = true;
				answer[i][j] = 0;
			} else{
				if(find){
					answer[i][j] = answer[i][j - 1] + 1;
				} else{
					answer[i][j] = -1;
				}
			}
		}
	}
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
