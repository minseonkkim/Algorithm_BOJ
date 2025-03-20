#include <iostream>
using namespace std;

int n, k;
int score[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> score[i];
		sum += score[i];
	}
	
	int l = 0, r = sum, answer = 0;
	while(l <= r){
		int mid = (l + r) / 2;
		
		int sm = 0, cnt = 0;
		for(int i = 0; i < n; i++){
			sm += score[i];
			if(sm >= mid){
				sm = 0;
				cnt++;
			}
		}
		
		if(cnt < k) r = mid - 1;
		else {
			l = mid + 1;
			answer = mid;
		}
	}
	cout << answer;
	return 0;
}
