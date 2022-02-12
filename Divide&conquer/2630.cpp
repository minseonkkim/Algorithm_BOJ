#include <iostream>
using namespace std;
 
int n;
int paper[129][129];
int w_cnt = 0, b_cnt = 0;
 
void divconquer(int x, int y, int v){
	int cnt = 0;
	for(int i = x; i < x + v; i++){
		for(int j = y; j < y + v; j++){
			if(paper[i][j]) cnt++;
		}
	}
 
	if(cnt == 0) w_cnt++;
	else if(cnt == v * v) b_cnt++;
	else{
		divconquer(x, y, v / 2);
		divconquer(x, y + v / 2, v / 2);
		divconquer(x + v / 2, y, v / 2);
		divconquer(x + v / 2, y + v / 2, v / 2);
	}
}
 
int main() {
	cin >> n;
 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> paper[i][j];
		}
	}
	divconquer(0, 0, n);
 
	cout << w_cnt << endl;
	cout << b_cnt << endl;
	return 0;
}
