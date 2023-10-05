#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
int ans[8];

void getAnswer(int idx){
	if(idx == m){
		for(int i = 0; i < m; i++){
			cout << ans[i] << " ";
		}
		cout << '\n';
	} else{
		for(int i = 0; i < n; i++){
			ans[idx] = arr[i];
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
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	getAnswer(0);
	return 0;
}
