#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, mn, q;
	string group, member, name;
	vector<pair<string, string>> v;
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> group >> mn;
		for(int j = 0; j < mn; j++){
			cin >> member;
			v.push_back({group, member});
		}
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < m; i++){
		cin >> name >> q;
		if(q == 0){
			for(int j = 0; j < v.size(); j++){
				if(v[j].first == name) {
					cout << v[j].second << endl;
				}
			}
		} else{
			for(int j = 0; j < v.size(); j++){
				if(v[j].second == name) {
					cout << v[j].first << endl;
					break;
				}
			}
		}
	}
	return 0;
}
