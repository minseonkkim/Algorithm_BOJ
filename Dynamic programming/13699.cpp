#include <iostream>
using namespace std;

int main() {
	long long arr[36] = { 0, };
	int n;
	cin >> n;
	
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			arr[i] += arr[j] * arr[i - j - 1];
		}
	}

	cout << arr[n] << endl;
	return 0;
}
