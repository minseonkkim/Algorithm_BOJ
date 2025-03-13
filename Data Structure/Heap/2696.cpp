#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		priority_queue<int> small;
		priority_queue<int, vector<int>, greater<int>> big;
		vector<int> answer;
		int m;
		cin >> m;
		
		for(int i = 1; i <= m; i++){
			int x;
			cin >> x;
			
			if(small.size() == big.size()) small.push(x);
			else big.push(x);
			
			
			if(!small.empty() && !big.empty() && small.top() > big.top()){
				int st = small.top();
				int bt = big.top();
				
				small.pop();
				big.pop();
				
				big.push(st);
				small.push(bt);
			}
			
			if(i % 2 != 0) answer.push_back(small.top());
		}
		
		cout << answer.size() << '\n';
		for(int i = 0; i < answer.size(); i++){
			cout << answer[i];
			if((i + 1) % 10 == 0 || i == answer.size() - 1) cout << '\n';
			else cout << " ";
		}
	}
	
	return 0;
}
