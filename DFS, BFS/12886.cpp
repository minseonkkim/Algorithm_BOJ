#include <iostream>
#include <queue>
using namespace std;

struct group{
	int a, b, c;
};

int x, y, z;
bool visited[1501][1501];

void bfs(){
	queue<group> q;
	q.push({x, y, z});
	visited[x][y] = true;
	
	while(!q.empty()){
		int ca = q.front().a;
		int cb = q.front().b;
		int cc = q.front().c;
		q.pop();
		
		if(ca == cb && cb == cc){
			cout << 1;
			return;
		}
		
		if(ca != cb){
			int na, nb, nc;
			if(ca > cb){
				na = ca - cb;
				nb = cb + cb;
				nc = cc;
			} else{
				na = ca + ca;
				nb = cb - ca;
				nc = cc;
			}
			
			if(!visited[na][nb]){
				visited[na][nb] = true;
				q.push({na, nb, nc});
			}
		}
		
		if(ca != cc){
			int na, nb, nc;
			if(ca > cc){
				na = ca - cc;
				nb = cb;
				nc = cc + cc;
			} else{
				na = ca + ca;
				nb = cb;
				nc = cc - ca;
			}
			
			if(!visited[na][nb]){
				visited[na][nb] = true;
				q.push({na, nb, nc});
			}
		}
		
		if(cb != cc){
			int na, nb, nc;
			if(cb > cc){
				na = ca;
				nb = cb - cc;
				nc = cc + cc;
			} else{
				na = ca;
				nb = cb + cb;
				nc = cc - cb;
			}
			
			if(!visited[na][nb]){
				visited[na][nb] = true;
				q.push({na, nb, nc});
			}
		}
	}
	cout << 0;
	return;
}

int main() {
	cin >> x >> y >> z;
	bfs();
	
	return 0;
}
