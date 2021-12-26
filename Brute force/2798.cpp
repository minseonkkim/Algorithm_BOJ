#include <iostream>
using namespace std;

int main() {
	int n, m, num;
	cin >> n >> m;
	
	int v[101];
	
	for(int i = 0; i < n; i++){
		cin >> num;
		v[i] = num;
	}
	
	int sum, max = 0;
	for(int i = 0; i < n - 2; i++){
		for(int j = i + 1; j < n - 1; j++){
			for(int k = j + 1; k < n; k++){
				sum = v[i] + v[j] + v[k];
				if(sum <= m && sum > max) max = sum;
			}
		}
	}
	cout << max << endl;

	return 0;
}
