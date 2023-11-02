#include <iostream>
#include <map>
#include <queue>
using namespace std;

long long s, t;

bool bfs(){
	bool flag = false;
	queue<pair<long long, string>> q;
	map<long long, bool> visited;
	q.push({s, ""});
	visited[s] = true;
	
	while(!q.empty()){
		long long curnum = q.front().first;
		string curop = q.front().second;
		if(curnum == t){
			cout << curop;
			flag = true;
			break;
		}
		q.pop();
		
		for(int i = 0; i < 4; i++){
			if(i == 0){
				long long nextnum = curnum * curnum;
				string nextop = curop + '*';
				
				if(visited[nextnum]) continue;
				
				q.push({nextnum, nextop});
				visited[nextnum] = true;
			} else if(i == 1){
				long long nextnum = curnum + curnum;
				string nextop = curop + '+';
				
				if(visited[nextnum]) continue;
				
				q.push({nextnum, nextop});
				visited[nextnum] = true;
			} else if(i == 2){
				long long nextnum = curnum - curnum;
				string nextop = curop + '-';
				
				if(visited[nextnum]) continue;
				
				q.push({nextnum, nextop});
				visited[nextnum] = true;
			} else{
				if(curnum == 0) continue;
				
				long long nextnum = curnum / curnum;
				string nextop = curop + '/';
				
				if(visited[nextnum]) continue;
				
				q.push({nextnum, nextop});
				visited[nextnum] = true;
			}
		}
	}
	return flag;
}

int main() {
	cin >> s >> t;
	
	if(s == t) {
		cout << 0;
		return 0;
	}
	bool f = bfs();
	if(!f) {
		cout << -1;
	}
	return 0;
}
