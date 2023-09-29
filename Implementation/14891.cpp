#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> q[5];

// spr: 0-왼쪽, 1-양방향, 2-오른쪽
void setRotation(int num, int dir, int spr){
	
	if(num > 1 && q[num - 1][2] != q[num][6] && (spr == 0 || spr == 1)){
		if(dir == -1) setRotation(num - 1, 1, 0);
		else if(dir == 1) setRotation(num - 1, -1, 0);
	}
	if(num < 4 && q[num][2] != q[num + 1][6] && (spr == 1 || spr == 2)){
		if(dir == -1) setRotation(num + 1, 1, 2);
		else if(dir == 1) setRotation(num + 1, -1, 2);
	}
	if(dir == -1){
		int tmp = q[num].front();
		q[num].pop_front();
		q[num].push_back(tmp);
	} else if(dir == 1){
		int tmp = q[num].back();
		q[num].pop_back();
		q[num].push_front(tmp);
	}
}

int main() {
	for(int i = 1; i <= 4; i++){
		string str;
		cin >> str;
		for(int j = 0; j < str.length(); j++){
			q[i].push_back(str[j] - '0');
		}
	}
	
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		int num, dir;
		cin >> num >> dir;
		setRotation(num, dir, 1);
	}
	
	int ans = 0;
	if(q[1][0] == 1) ans += 1;
	if(q[2][0] == 1) ans += 2;
	if(q[3][0] == 1) ans += 4;
	if(q[4][0] == 1) ans += 8;
	
	cout << ans << endl;
	return 0;
}
