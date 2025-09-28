#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, s;
vector<int> v[100001];
bool isfan[100001];
bool answer;

bool bfs(){
	queue<int> q;
	if(isfan[1]) return false;
	q.push(1);
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		if(v[cur].size() == 0) return true;
		for(int i = 0; i < v[cur].size(); i++){
			int nxt = v[cur][i];
			if(!isfan[nxt]){
				q.push(nxt);
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	cin >> s;
	for(int i = 0; i < s; i++){
		int x;
		cin >> x;
		isfan[x] = true;
	}
	
	answer = bfs();
	
	if(answer) cout << "yes";
	else cout << "Yes";
	return 0;
}
