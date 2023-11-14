#include <iostream>
using namespace std;

int n, heartx, hearty, l_arm, r_arm, waist, l_leg, r_leg;
char map[1001][1001];

int main() {
	cin >> n;
	bool find = false;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> map[i][j];
			if(!find && map[i][j] == '*'){
				heartx = i;
				hearty = j;
				find = true;
			}
		}
	}
	heartx++;
	int t = hearty - 1;
	while(true){
		if(t <= 0) break;
		if(map[heartx][t] == '_') break;
		l_arm++;
		t--;
	}
	t = hearty + 1;
	while(true){
		if(t > n) break;
		if(map[heartx][t] == '_') break;
		r_arm++;
		t++;
	}
	t = heartx + 1;
	while(true){
		if(t > n) break;
		if(map[t][hearty] == '_') break;
		waist++;
		t++;
	}
	int t2 = t;
	while(true){
		if(t > n) break;
		if(map[t][hearty - 1] == '_') break;
		l_leg++;
		t++;
	}
	while(true){
		if(t2 > n) break;
		if(map[t2][hearty + 1] == '_') break;
		r_leg++;
		t2++;
	}
	
	cout << heartx << " " << hearty << endl;
	cout << l_arm << " " << r_arm << " " << waist << " " << l_leg << " " << r_leg;
	return 0;
}
