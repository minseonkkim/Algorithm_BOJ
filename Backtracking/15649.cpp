#include <iostream>
using namespace std;

int n, m;
int arr[9];
int visited[9];

void dfs(int k) {
	if (k == m + 1) {
		for (int i = 1; i <= m; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[k] = i;
				dfs(k + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1);
	return 0;
}
