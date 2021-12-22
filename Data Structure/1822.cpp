#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, k;
	cin >> n >> m;
	
	set<int> s;
	
	for(int i = 0; i < n; i++){
		cin >> k;
		s.insert(k);
	}
	for(int j = 0; j < m; j++){
		cin >> k;
		s.erase(k);
	}
	
	cout << s.size() << endl;
	for(auto it = s.begin(); it != s.end(); it++){
		cout << *it << ' ';
	}
	return 0;
}
