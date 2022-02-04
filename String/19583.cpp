#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string t1, t2, t3, time, name;
	int t, cnt = 0;
	
	cin >> t1 >> t2 >> t3;
	set<string> first;
	int s = 60 * stoi(t1.substr(0, 2)) + stoi(t1.substr(3, 2));
	int e = 60 * stoi(t2.substr(0, 2)) + stoi(t2.substr(3, 2));
	int q = 60 * stoi(t3.substr(0, 2)) + stoi(t3.substr(3, 2));

	while(cin >> time >> name){
		t = 60 * stoi(time.substr(0, 2)) + stoi(time.substr(3, 2));
		
		if(t <= s){
			first.insert(name);
		}
		
		if(t >= e && t <= q){
			if(first.find(name) != first.end()){
				cnt++;
				first.erase(name);
			}
		}
	}
	
	cout << cnt << endl;
	return 0;
}
