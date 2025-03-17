#include <iostream>
using namespace std;

int n;
int num[11];
int answer[11];

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> num[i];
	
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			if(answer[j] == 0){
				if(cnt >= num[i]){
					answer[j] = i;
					break;
				}
				cnt++;
			}
		}
	}
	
	for(int i = 1; i <= n; i++) 
		cout << answer[i] << " ";
	return 0;
}
