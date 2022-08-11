#include <iostream>
#include <algorithm>
using namespace std;

int n, m, r;
int arr[301][301];

void rotate(int start, int len){
	int t = r % len;
	for(int i = 0; i < t; i++){
		int tmp = arr[start][start];
		for(int j = start + 1; j <= m - start + 1; j++)
			arr[start][j - 1] = arr[start][j];
		for(int j = start + 1; j <= n - start + 1; j++)
			arr[j - 1][m - start + 1] = arr[j][m - start + 1];
		for(int j = m - start + 1; j >= start + 1; j--)
			arr[n - start + 1][j] = arr[n - start + 1][j - 1];
		for(int j = n - start + 1; j >= start + 2; j--)
			arr[j][start] = arr[j - 1][start];
		arr[start + 1][start] = tmp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> r;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	
	int cnt = min(n, m) / 2;
	int N = n, M = m;
	
	for(int i = 1; i <= cnt; i++){
		rotate(i, 2 * N + 2 * M - 4);
		N -= 2;
		M -= 2;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
