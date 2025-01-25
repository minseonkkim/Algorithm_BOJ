#include <iostream>
#include <cmath>
using namespace std;
 
int n;
int triangle[501][501];
 
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin >> triangle[i][j];
		}
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(j == 1) triangle[i][j] += triangle[i - 1][1];
			else if(j == i) triangle[i][j] += triangle[i - 1][j - 1];
			else triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
		}
	}
	int answer = 0;
	for(int i = 1; i <= n; i++){
		if(triangle[n][i] > answer) answer = triangle[n][i];
	}
	cout << answer;
	return 0;
}
