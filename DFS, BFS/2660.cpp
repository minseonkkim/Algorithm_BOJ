#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> know[51];
vector<pair<int, int>> ans;  // 점수, 회원번호

int bfs(int n){
	queue<pair<int, int>> q;
	q.push({n, 0});
	bool visited[51] = {false, };
	visited[n] = true;
	int ret = 0;
	
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		if(cnt > ret) ret = cnt;
		q.pop();
		
		for(int i = 0; i < know[cur].size(); i++){
			int next = know[cur][i];
			int ncnt = cnt + 1;
			
			if(visited[next]) continue;
			visited[next] = true;
			q.push({next, ncnt});
		}
	}
	
	return ret;
}

int main() {
	int num;
	cin >> num;
	while(true){
		int a, b;
		cin >> a >> b;
		if(a == -1 && b == -1) break;
		
		know[a].push_back(b);
		know[b].push_back(a);
	}
	
	for(int i = 1; i <= num; i++){
		int score = bfs(i);
		ans.push_back({score, i});
	}
	
	sort(ans.begin(), ans.end());
	
	int candiscore = ans[0].first;
	int candinum = 1;
	bool find = false;
	for(int i = 1; i < ans.size(); i++){
		if(ans[i].first != candiscore){
			candinum = i;
			find = true;
			break;
		}
	}
	if(!find) candinum = ans.size();
	
	cout << candiscore << " " << candinum << '\n';
	for(int i = 0; i < candinum; i++){
		cout << ans[i].second << " ";
	}
	
	return 0;
}
