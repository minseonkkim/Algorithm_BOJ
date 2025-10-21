#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<string, int>> v;
	v.push_back({"", 0});
	for(int i = 1; i <= n; i++){
		string cmd;
		cin >> cmd;
		if(cmd == "type"){
			char ch; int t;
			cin >> ch >> t;
			v.push_back({v[i - 1].first + ch, t});
		} else{
			int bn, t;
			cin >> bn >> t;
			int idx = 0;
			for(int j = i - 1; j >= 0; j--){
				if(t - bn > v[j].second){
					idx = j;
					break;
				} 
			}
			if(idx == 0){
				v.push_back({"", t});
			} else{
				v.push_back({v[idx].first, t});
			}
		}
	}
	cout << v[v.size() - 1].first;
	return 0;
}
