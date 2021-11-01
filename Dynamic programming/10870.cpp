#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;

	vector<int> fibarr;
	fibarr.push_back(0);
	fibarr.push_back(1);

	for (int i = 2; i <= n; i++) {
		int num = fibarr[i - 1] + fibarr[i - 2];
		fibarr.push_back(num);
	}

	return fibarr[n];
}

int main() {
	int num;
	cin >> num;

	cout << fib(num) << endl;
	return 0;
}
