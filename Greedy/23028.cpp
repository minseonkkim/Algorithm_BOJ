#include <iostream>
using namespace std;
 
int main() {
	int n, a, b, x, y;
	cin >> n >> a >> b;
 
	int rs = 8 - n;  // 남은 학기
	int rg = 66 - a;   // 남은 전공 학점
	int rc = 130 - b;  // 남은 총 학점
 
	for(int i = 0; i < 10; i++){
		cin >> x >> y;
 
		if(i < rs){
			if(x + y > 6){
				int r = (x + y) - 6;
				rg = rg - x * 3;
				rc = rc - (x * 3 + (y - r) * 3);
			} else{
				rg = rg - x * 3;
				rc = rc - (x * 3 + y * 3);
			}
		}
	}
 
	if(rg <= 0 && rc <= 0){
		cout << "Nice" << endl;
	} else {
		cout << "Nae ga wae" << endl;
	}
	return 0;
}
