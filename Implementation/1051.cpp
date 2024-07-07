#include <iostream>
using namespace std;

int n, m;
int square[50][50];

int main() {
	cin >> n >> m;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			square[i][j] = s[j] - '0';
		}
	}

	int min = n > m ? m : n;
	bool find = false;
	for (int k = min; k >= 1; k--) {  // 정사각형 변 길이
		for (int i = 0; i <= n - k; i++) {
			for (int j = 0; j <= m - k; j++) {
				int lt = square[i][j];
				int lb = square[i + k - 1][j];
				int rt = square[i][j + k - 1];
				int rb = square[i + k - 1][j + k - 1];
				if (lt == lb && lt == rt && lt == rb && lb == rt && lb == rb && rt == rb) {
					find = true;
					break;
				}
			}
			if (find) break;
		}
		if (find) {
			cout << k * k;
			break;
		}
	}
}
