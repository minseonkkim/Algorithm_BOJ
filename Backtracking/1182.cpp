#include <iostream>
using namespace std;

int n, s, ans;
int arr[20];

void func(int x, int sum) {
	if (x == n) {
		if (sum == s) {
			ans++;
		}
		return;
	}

	func(x + 1, sum + arr[x]);
	func(x + 1, sum);
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	func(0, 0);
	if (s == 0) ans--;

	cout << ans;
}
