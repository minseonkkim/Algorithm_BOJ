#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m, num, x, y;
	cin >> n >> m;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> num;
		v[i] = v[i - 1] + num;
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		cout << v[y] - v[x - 1] << '\n';
	}
	return 0;
}
