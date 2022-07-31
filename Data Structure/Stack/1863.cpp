#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> v;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v.push_back(b);
	}
	
	stack<int> st;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		while(!st.empty() && v[i] < st.top()) {
			if(st.top() != 0) cnt++;
			st.pop();
		}
		if(!st.empty() && v[i] == st.top()) continue;
		st.push(v[i]);
	}
	while(!st.empty()){
		if(st.top() != 0) cnt++;
		st.pop();
	}
	cout << cnt << endl;
	return 0;
}
