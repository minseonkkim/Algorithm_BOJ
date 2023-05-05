#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> rion_position;
	
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x == 1) rion_position.push_back(i);
	}
	
	if(rion_position.size() < k){
		cout << -1 << endl;
		return 0;
	}
	
	int ans = 1000001;
	for(int i = 0; i <= rion_position.size() - k; i++){
		ans = min(ans, rion_position[i + k - 1] - rion_position[i] + 1);
	}
	cout << ans << endl;
	return 0;
}
