#include <iostream>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	for(int z=0;z<t;z++){
		
		int N, K;
		cin >> N >> K;
		int arr[1000000] = {0,};
		int cnt = 0, mini = INT_MAX;
		
		for(int i=0;i<N;i++) cin >> arr[i];
		sort(arr, arr+N);
		
		int lp = 0, rp = N-1;
		while(lp < rp){
			int a = arr[lp];
			int b = arr[rp];
			if(K == a + b){ lp++; rp--;}
			else if(K < a + b) rp--;
			else lp++;
			
			if(abs(K-(a+b)) < mini){
				mini = abs(K-(a+b));
				cnt = 1;
			}
			else if(abs(K-(a+b))==mini) cnt++;
		}
		
		cout << cnt << '\n';
	}
	return 0;
}
