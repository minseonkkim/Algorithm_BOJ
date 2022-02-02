#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string str;
	map<string, int> m;
	
	for(int i = 0; i < n; i++){
		cin >> str;
		int idx = str.find('.');
		str = str.substr(idx + 1);
		if(m.find(str) != m.end()){
			m[str]++;
		} else {
			m[str] = 1;
		}
	}
	
	for(auto iter = m.begin(); iter != m.end(); iter++){
		cout << iter->first << " " << iter->second << endl;
	}

	return 0;
}
