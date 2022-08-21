#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> v;
	int day[10001] = {0, };
	int maxday = 0;
	for(int i = 0; i < n; i++){
		int p, d;
		cin >> p >> d;
		if(d > maxday) maxday = d;
		v.push_back({p, d});
	}
	sort(v.begin(), v.end(), greater<>());
	
	for(int i = 0; i < n; i++){
		int q = v[i].second;
		while(q > 0){
			if(day[q] == 0){
				day[q] = v[i].first;
				break;
			}
			q--;
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= maxday; i++){
		ans += day[i];
	}
	cout << ans << endl;
	return 0;
}
