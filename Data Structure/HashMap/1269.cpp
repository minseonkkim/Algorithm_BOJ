#include <iostream>
#include <vector>
#include <map>
using namespace std;

int a, b, num, ans;
map<int, int> m;

int main() {
	cin >> a >> b;
	for (int i = 0; i < a + b; i++) {
		cin >> num;
		m[num]++;
	}
	for (auto x : m) {
		if (x.second == 1) ans++;
	}
	cout << ans;
}
