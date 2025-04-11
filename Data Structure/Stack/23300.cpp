#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	stack<int> back;
	stack<int> forward;
	int cur = -1;
	
	for(int i = 0; i < q; i++){
		char cmd;
		cin >> cmd;
		if(cmd == 'B'){
			if(back.empty()) continue;
			forward.push(cur);
			cur = back.top();
			back.pop();
		} else if(cmd == 'F'){
			if(forward.empty()) continue;
			back.push(cur);
			cur = forward.top();
			forward.pop();
		} else if(cmd == 'A'){
			int num;
			cin >> num;
			while(!forward.empty()) forward.pop();
			if(cur != -1) back.push(cur);
			cur = num;
		} else{
			vector<int> tmp;
			while(!back.empty()){
				if(tmp.empty() || tmp.back() != back.top())
					tmp.push_back(back.top());
				back.pop();
			}
			reverse(tmp.begin(), tmp.end());
			for(int i = 0; i < tmp.size(); i++) back.push(tmp[i]);
		}
	}
	cout << cur << '\n';
	if(back.empty()) cout << -1;
	else{
		while(!back.empty()){
			cout << back.top() << " ";
			back.pop();
		}
	}
	cout << '\n';
	if(forward.empty()) cout << -1;
	else{
		while(!forward.empty()){
			cout << forward.top() << " ";
			forward.pop();
		}
	}
	
	return 0;
}
