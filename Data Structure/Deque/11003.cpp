#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n, l;
	cin >> n >> l;
	
	vector<int> v;
    int num;
	for(int i = 0; i < n; ++i){
		cin >> num;
		v.push_back(num);
	}
	
	deque<pair<int, int>> dq;
	for(int i = 0; i < n; ++i){
		if(!dq.empty() && i == dq.front().second + l)
			dq.pop_front();
		while(!dq.empty() && dq.back().first > v[i])
			dq.pop_back();
		dq.push_back({v[i], i});
		cout << dq.front().first << " ";
	}
	
	return 0;
}
