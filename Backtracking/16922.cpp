#include <iostream>
#include <set>
using namespace std;

int n;
set<int> s;
int chars[4] = {1, 5, 10, 50};

void dfs(int cnt, int start, int sum){
	if(cnt == n){
		s.insert(sum);
        return;
	} else{
		for(int i = start; i < 4; i++){
			dfs(cnt + 1, i, sum + chars[i]);
		}
	}
	
}

int main() {
	cin >> n;
	dfs(0, 0, 0);
	cout << s.size();
	return 0;
}
