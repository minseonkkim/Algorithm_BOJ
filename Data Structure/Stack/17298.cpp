#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, num;
	cin >> n;
	
	vector<int> v;
	stack<int> s;
	vector<int> res;
	
	for(int i = 0; i < n; i++){
		cin >> num;
		v.push_back(num);
	}
	for(int i = v.size() - 1; i >= 0; i--){
		while(!s.empty() && s.top() <= v[i]){
			s.pop();
		}
		if(s.empty()) res.push_back(-1);
		else res.push_back(s.top());
		s.push(v[i]);
	}
	for(int i = res.size() - 1; i >= 0; i--){
		cout << res[i] << " ";
	}
	return 0;
}
