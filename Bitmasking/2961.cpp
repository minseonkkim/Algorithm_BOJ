#include <iostream>
#include <cmath>
using namespace std;

int n;
int ans = 987654321;
int ingredients[10][2];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> ingredients[i][0];
		cin >> ingredients[i][1];
	}
	int noc = 1 << n;  // 모든 경우의 수
	for(int i = 1; i < noc; i++){  // 공집합(0) 제외
		int sour = 1;
		int bitter = 0;
		for(int j = 0; j < n; j++){
			if((i & (1 << j)) != 0){  // 해당 재료가 경우의 수에 포함되어 있는지
				sour *= ingredients[j][0];
				bitter += ingredients[j][1]; 
			}
		}
		if(abs(sour - bitter) < ans){
			ans = abs(sour - bitter);
		}
	}
	cout << ans;
	return 0;
}
