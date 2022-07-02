#include <iostream>
using namespace std;

int main() {
	int num[1001];
	int n, k;
	int cnt = 0;
	cin >> n >> k;
	
	for(int i = 2; i <= n; i++)
		num[i] = i;
	
	for(int i = 2; i <= n; i++){
		if(num[i] == 0) continue;
		else{
			for(int j = i; j <= n; j += i){
				if(num[j] != 0){
					num[j] = 0;
					cnt++;
				}
				if(cnt == k){
					cout << j << endl;
					return 0;
				}
			}
		}
	}
}
