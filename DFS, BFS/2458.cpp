#include <iostream>
#include <vector>
using namespace std;

int n, m;
int count, answer;
vector<int> v[501];
vector<int> iv[501];
bool visited[501];

void dfs(int x){
	visited[x] = true;
	
	for(int i = 0; i < v[x].size(); i++){
		int nx = v[x][i];
		if(visited[nx]) continue;
		dfs(nx);
		count++;
	}
}

void idfs(int x){
	visited[x] = true;
	
	for(int i = 0; i < iv[x].size(); i++){
		int nx = iv[x][i];
		if(visited[nx]) continue;
		idfs(nx);
		count++;
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		iv[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		count = 0;
		dfs(i);
		for(int j = 1; j <= n; j++){
			visited[j] = false;
		}
		idfs(i);
		for(int j = 1; j <= n; j++){
			visited[j] = false;
		}
		if(count == n - 1) answer++;
	}
	cout << answer;
	return 0;
}
