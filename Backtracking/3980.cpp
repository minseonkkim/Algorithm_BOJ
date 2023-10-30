#include <iostream>
#include <algorithm>
using namespace std;
 
int arr[11][11];
bool position[11];
int answer = -1;
 
void dfs(int idx, int result){
	if(idx == 11){
		answer = max(answer, result);
	}
 
	for(int i = 0; i < 11; i++){
        if(arr[idx][i] == 0) continue;
		if(!position[i]){
			position[i] = true;
			dfs(idx + 1, result + arr[idx][i]);
			position[i] = false;
		}
	}
}
 
int main() {
	int c;
	cin >> c;
	for(int test_case = 0; test_case < c; test_case++){
		for(int i = 0; i < 11; i++){
			for(int j = 0; j < 11; j++){
				cin >> arr[i][j];
			}
		}
		dfs(0, 0);
 
		cout << answer << '\n';
		answer = -1;
	}
 
	return 0;
}
