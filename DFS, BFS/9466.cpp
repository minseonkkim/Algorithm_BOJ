#include <iostream>
using namespace std;

int n, ans;
int select_student[100001];
bool finished[100001];
bool visited[100001];

void dfs(int x){
    visited[x] = true;
	
	int nx = select_student[x];
	if(!visited[nx]) dfs(nx);
	else{
		if(!finished[nx]){
			for(int i = nx; i != x; i = select_student[i]){
				ans++;
			}
			ans++;
		}
	}
	
	finished[x] = true;
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		for(int i = 1; i <= 100001; i++) {
            finished[i] = false;
            visited[i] = false;
            ans = 0;
        }
		
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> select_student[i];
		}
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				dfs(i);
			}
		}
		cout << n - ans << '\n';
	}
	return 0;
}
