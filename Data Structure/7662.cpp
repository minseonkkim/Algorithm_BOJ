#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k, num;
	char c;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		multiset<int> ms;
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> c;
			if(c == 'I'){
				cin >> num;
				ms.insert(num);
			} else if(c == 'D'){
				cin >> num;
				if(ms.empty()) continue;
				if(num == -1) ms.erase(ms.begin());
				else if(num == 1) {
					auto it = ms.end();
					it--;
					ms.erase(it);
				}
			}
		}
		if(ms.empty()) cout << "EMPTY" << '\n';
		else {
			auto it = ms.end();
			it--;
			cout << *it << " " << *ms.begin() << '\n';
		}
	}
	return 0;
}
