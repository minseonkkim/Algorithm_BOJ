#include <iostream>
using namespace std;

int n, k;
int gain[8];
bool visited[8];
int weight = 500;
int answer = 0;

void dfs(int count){
	if(count == n) answer++;
	else{
		for(int i = 0; i < n; i++){
			if(!visited[i]){
				visited[i] = true;
				if(weight + gain[i] - k >= 500){
					weight += gain[i] - k;
					dfs(count + 1);
					weight -= gain[i] - k;
				}
				visited[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> gain[i];
	}
	dfs(0);
    cout << answer;
	return 0;
}
