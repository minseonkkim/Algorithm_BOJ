#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
int arr[8];
set<vector<int>> s;

void getAnswer(int idx){
	if(idx == m){
		vector<int> ans;
		for(int i = 0; i < m; i++){
			ans.push_back(arr[i]);
		}
		s.insert(ans);
		ans.clear();
	} else{
		for(int i = 0; i < n; i++){
			arr[idx] = v[i];
			getAnswer(idx + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	getAnswer(0);
	
	for(auto i:s){
		for(auto j:i){
			cout << j << " ";
		}
		cout << '\n';
	}
	return 0;
}
