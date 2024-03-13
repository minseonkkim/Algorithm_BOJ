#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int budget[10000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> budget[i];
	}
	cin >> m;

	sort(budget, budget + n);

	int left = 0, right = budget[n - 1];
	int sum, result;
	while (left <= right) {
		sum = 0;
		int mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			if (budget[i] < mid) sum += budget[i];
			else sum += mid;
		}
		if (sum > m) right = mid - 1;
		else {
			left = mid + 1;
			result = mid;
		}
	}

	cout << result;
}
