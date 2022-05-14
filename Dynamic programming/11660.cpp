#include <stdio.h>
using namespace std;

int arr[1025][1025];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	int num;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &num);
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] + num - arr[i - 1][j - 1];
		}
	}
	
	int a, b, c, d;
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d\n", arr[c][d] - arr[a - 1][d] - arr[c][b - 1] + arr[a - 1][b - 1]);
	}
	return 0;
}
