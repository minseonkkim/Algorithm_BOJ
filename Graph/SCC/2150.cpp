#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001
using namespace std;

int v, e, id;
vector<int> a[MAX];
int d[MAX];
bool finished[MAX];
stack<int> s;
int sccNum;
vector<vector<int>> SCC;

int dfs(int c){
	d[c] = ++id;  // 정점에 고유 id 할당
	s.push(c);   // 스택에 자신을 삽입
	
	int result = d[c];
	for(int next : a[c]){
		// 아직 방문하지 않은 정점이면
		if(d[next] == 0) result = min(result, dfs(next));
		// 방문은 했으나 아직 SCC로 성립하지 않은 정점이면
		else if(!finished[next]) result = min(result, d[next]);
	}
	
	// 자신과 자신의 자식 정점들이 갈 수 있는 가장 높은 정점이 자신인 경우 SCC 추출
	if(result == d[c]){
		vector<int> scc;
		// 스택에서 자신이 나올 때까지 pop
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if(t == c) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
		sccNum++;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// 그래프 정보 입력
	cin >> v >> e;
	for(int i = 0; i < e; i++){
		int p, q;
		cin >> p >> q;
		a[p].push_back(q);
	}
	// DFS 수행하며 SCC 추출
	for(int i = 1; i < v; i++){
		if(d[i] == 0) dfs(i);
	}
	sort(SCC.begin(), SCC.end());
	cout << sccNum << endl;
	// 각 SCC 출력
	for(auto& currSCC : SCC){
		for(int curr : currSCC)
			cout << curr << " ";
		cout << -1 << endl;
	}
	return 0;
}
