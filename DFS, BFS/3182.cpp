#include <iostream>
using namespace std;

int n;
int arr[1001];

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	int ans = -1, maxcnt = -1;
	for(int i = 1; i <= n; i++){
		int nxt = i;
		int cnt = 1;
		bool visited[1001] = {false, };
		visited[i] = true;
		while(true){
			nxt = arr[nxt];
			if(visited[nxt]) break;
			cnt++;
			visited[nxt] = true;
		}
		
		if(cnt > maxcnt){
			maxcnt = cnt;
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
