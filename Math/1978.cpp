#include <iostream>
using namespace std;

int cnt = 0;

void isPrime(int n) {
	if (n == 1) return;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return;
	}
	cnt++;
}

int main() {
	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		isPrime(num);
	}
	cout << cnt << endl;

	return 0;
}
