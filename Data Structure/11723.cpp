#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m;
	cin >> m;
	
	set<int> s;
    set<int> tmp;
    for(int i = 1; i <= 20; i++) tmp.insert(i);
	string str;
	int k;
	for(int i = 0; i < m; i++){
		cin >> str;
		if(str == "add"){
			cin >> k;
			s.insert(k);
		} else if(str == "remove"){
			cin >> k;
			s.erase(k);
		} else if(str == "check"){
			cin >> k;
			if(s.find(k) == s.end()){
				cout << "0\n";
			} else{
				cout << "1\n";
			}
		} else if(str == "toggle"){
			cin >> k;
			if(s.find(k) == s.end()){
				s.insert(k);
			} else{
				s.erase(k);
			}
		} else if(str == "all"){
			s = tmp;
		} else if(str == "empty"){
			s.clear();
		}
	}
	
	
	return 0;
}
