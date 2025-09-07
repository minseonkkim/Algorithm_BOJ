#include <iostream>
using namespace std;
 
int hurtfinger;
long long maxcnt, answer;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> hurtfinger >> maxcnt;
 
	if(hurtfinger == 1){
		answer = 8 * maxcnt;
	} else if(hurtfinger == 2){
		if(maxcnt % 2 == 0){
			answer = 8 * (maxcnt / 2) + 1;
		} else{
			answer = 8 * (maxcnt / 2 + 1) - 1;
		}
	} else if(hurtfinger == 3){
		answer = 2 + 4 * maxcnt;
	} else if(hurtfinger == 4){
		if(maxcnt % 2 == 0){
			answer = 4 * maxcnt + 3;
		} else{
			answer = 4 * maxcnt + 1;
		}
	} else{
		answer = 12 + (maxcnt - 1) * 8;
	}
	cout << answer;
	return 0;
}
