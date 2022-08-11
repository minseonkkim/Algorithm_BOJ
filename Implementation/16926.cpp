#include <iostream>
#include <algorithm>
using namespace std;

int n, m, r;
int arr[301][301];

void rotate(){
	int t = min(n, m) / 2;
	for(int i = 1; i <= t; i++){
		int tmp = arr[i][i];
		for(int j = i + 1; j <= m - i + 1; j++)
			arr[i][j - 1] = arr[i][j];
		for(int j = i + 1; j <= n - i + 1; j++)
			arr[j - 1][m - i + 1] = arr[j][m - i + 1];
		for(int j = m - i + 1; j >= i + 1; j--)
			arr[n - i + 1][j] = arr[n - i + 1][j - 1];
		for(int j = n - i + 1; j >= i + 2; j--)
			arr[j][i] = arr[j - 1][i];
		arr[i + 1][i] = tmp;
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
	
	for(int i = 0; i < r; i++) 
		rotate();
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
