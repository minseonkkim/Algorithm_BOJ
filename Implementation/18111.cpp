#include <iostream>
using namespace std;

int map[500][500];

int main() {
	int n, m, b;
	cin >> n >> m >> b;
	int maxnum = -1, minnum = 257;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
			maxnum = max(map[i][j], maxnum);
			minnum = min(map[i][j], minnum);
		}
	}
	int mintime = 987654321, ansk = 0;
	for(int k = minnum; k <= maxnum; k++){
		int up = 0, down = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(map[i][j] > k) down += (map[i][j] - k);
				else up += (k - map[i][j]);
			}
		}
		
		if(up > b + down) continue;
		int tm = up + down * 2;
		if(tm < mintime || (tm == mintime && k > ansk)) {
			mintime = tm;
			ansk = k;
		}
	}
	
	cout << mintime << " " << ansk;
	return 0;
}
