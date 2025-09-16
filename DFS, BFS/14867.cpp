#include <iostream>
#include <queue>
#include <map>
using namespace std;

queue<pair<pair<int, int>, int>> q;
map<pair<int, int>, bool> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	visited[{0, 0}] = true;
	q.push({{0, 0}, 0});
	
	while(!q.empty()){
		int b1 = q.front().first.first;
		int b2 = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if(b1 == c && b2 == d){
			cout << cnt;
			return 0;
		}
		
		// F(b1)
		if(!visited[{a, b2}]){
			visited[{a, b2}] = true;
			q.push({{a, b2}, cnt + 1});
		}
		
		// F(b2)
		if(!visited[{b1, b}]){
			visited[{b1, b}] = true;
			q.push({{b1, b}, cnt + 1});
		}
		
		// E(b1)
		if(!visited[{0, b2}]){
			visited[{0, b2}] = true;
			q.push({{0, b2}, cnt + 1});
		}
		
		// E(b2)
		if(!visited[{b1, 0}]){
			visited[{b1, 0}] = true;
			q.push({{b1, 0}, cnt + 1});
		}
		
		// M(b1, b2)
		int n1 = b1 <= (b - b2) ? 0 : b1 - (b - b2);
		int n2 = b1 <= (b - b2) ? b1 + b2 : b;
		if(!visited[{n1, n2}]){
			visited[{n1, n2}] = true;
			q.push({{n1, n2}, cnt + 1});
		}
		
		// M(b2, b1)
		n1 = b2 <= (a - b1) ? b1 + b2 : a;
		n2 = b2 <= (a - b1) ? 0 : b2 - (a - b1);
		if(!visited[{n1, n2}]){
			visited[{n1, n2}] = true;
			q.push({{n1, n2}, cnt + 1});
		}
	}
	cout << -1;
	return 0;
}
