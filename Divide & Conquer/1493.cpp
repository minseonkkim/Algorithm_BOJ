#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int length, width, height, n, cube[20], cnt = 0, fail = 0;
vector<pair<int, int>> v;

void divide(int length, int width, int height, int idx){
	if(length == 0 || width == 0 || height == 0) return;
	for(int i = idx; i < v.size(); i++){
		if(v[i].second != 0 && length >= v[i].first && width >= v[i].first && h >= v[i].first){
			v[i].second--;
			cnt++;
			divide(length - v[i].first, width, height, i);
			divide(v[i].first, width - v[i].first, height, i);
			divide(v[i].first, v[i].first, height - v[i].first, i);
			return;
		}
	}
	fail = 1;
}

int main() {
	cin >> length >> width >> height >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		cube[a] += b;
	}
	for(int i = 19; i >= 0; i--){
		if(cube[i] != 0){
			v.push_back({pow(2, i), cube[i]});
		}
	}
	divide(length, width, height, 0);
	if(fail) cout << -1;
	else cout << cnt << endl;
	return 0;
}
