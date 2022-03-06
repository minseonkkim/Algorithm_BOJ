#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, q, num, x, y;
	cin >> n >> q;
	vector<int> v(n + 1);
	vector<int> sum(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + v[i];
	}
	for(int i = 0; i < q; i++){
		cin >> x >> y;
		cout << sum[y] - sum[x - 1] << '\n';
	}
	return 0;
}
