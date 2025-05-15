#include <iostream>
using namespace std;

int n, t;
int map[999][999];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> t;
	int num = 1, cx = n / 2, cy = n / 2, move = 1, dir = 0, cnt = 0;
	int tx = -1, ty = -1;
	map[cx][cy] = num;
	if(num == t){
		tx = cx + 1;
		ty = cy + 1;
	}
	num++;
	while(num <= n * n){
		
		for(int i = 0; i < move; i++){
			cx += dx[dir];
			cy += dy[dir];
			map[cx][cy] = num;
			
			if(num == t){
				tx = cx + 1;
				ty = cy + 1;
			}
			num++;
			
			if(num > n * n) break;
		}
		
		dir++; cnt++;
		if(dir == 4) dir = 0;
		if(cnt == 2) {
			cnt = 0;
			move++;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			 cout << map[i][j] << " ";
		}
		cout << '\n';
	}
	cout << tx << " " << ty;

	return 0;
}
