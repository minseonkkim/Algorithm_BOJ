#include <iostream>
#include <string>

using namespace std;

int room(int a, int b) {

	if (a == 0) return b;
	if (b == 1)return 1;

	return (room(a - 1, b) + room(a, b - 1));

}

int main() {
	int t;
	cin >> t;

	int k, n;
	int answer = 0;

	for (int i = 0;i < t;i++) {
		cin >> k >> n;
		cout << room(k, n) << endl;
	}
}
