#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> small;
priority_queue<int, vector<int>, greater<int>> big;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> n;
	for(int i = 0; i < n; i++){
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
		
		cout << small.top() << '\n';
	}
	
	return 0;
}
