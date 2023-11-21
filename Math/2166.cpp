#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<pair<int, int>> v;

long double solve(int i, int j){
	long double x1 = v[0].first, y1 = v[0].second;
	long double x2 = v[i].first, y2 = v[i].second;
	long double x3 = v[j].first, y3 = v[j].second;
	
	return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	long double ans = 0;
	for(int i = 1; i < n - 1; i++){
		ans += solve(i, i + 1);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans);
	return 0;
}
