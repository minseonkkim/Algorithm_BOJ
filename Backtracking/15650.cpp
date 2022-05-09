include <iostream>
using namespace std;

int n, m;
int arr[9];
bool isused[9];

void func(int s, int k) {
	if (k == m + 1) {
		for (int i = 1; i <= m; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = s; i <= n; i++) {
			if (!isused[i]) {
				isused[i] = true;
				arr[k] = i;
				func(i + 1, k + 1);
				isused[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	func(1, 1);
	return 0;
} 
