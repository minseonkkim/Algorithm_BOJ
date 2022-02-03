#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, x, y;
	cin >> n;
	
	vector<pair<int, int>> v;
	
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		v.push_back({x, y});
	}
	
	for(int i = 0; i < n; i++){
		int cnt = 1;
		for(int j = 0; j < n; j++){
			if(v[j].first > v[i].first && v[j].second > v[i].second){
				cnt++;
			}
		}
		cout << cnt << " ";
	}
	return 0;
}
