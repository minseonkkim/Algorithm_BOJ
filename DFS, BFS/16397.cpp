#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool visited[100000];

int main() {
	int N, T, G;
	cin >> N >> T >> G;
	
	queue<pair<int, int>> q;
	q.push({N, 0});
	visited[N] = true;
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cnt > T) {
			cout << "ANG";
			return 0;
		}
		if(cur == G){
			cout << cnt;
			return 0;
		}
		
		int next = cur + 1;
		if(!visited[next] && next <= 99999){
			q.push({next, cnt + 1});
			visited[next] = true;
		}
		
		next = cur * 2;
		if(next > 99999) continue;
		string nstr = to_string(next);
		for(int i = 0; i < nstr.length(); i++){
			if(nstr[i] != '0'){
				int tmp = nstr[i] - '0';
				tmp--;
				nstr[i] = tmp + '0';
				break;
			}
		}
		next = stoi(nstr);
		if(!visited[next] && next <= 99999){
			q.push({next, cnt + 1});
			visited[next] = true;
		}
	}
	cout << "ANG";
	return 0;
}
