#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string str;
	map<string, float> m;
	float cnt = 0;
	while(getline(cin, str)){
		cnt++;
		if(m.find(str) == m.end()){
			m[str] = 1;
		} else{
			m[str]++;
		}
	}
	
	cout << fixed;
	cout.precision(4);
	for(auto iter = m.begin(); iter != m.end(); iter++){
		float x = (iter->second / cnt) * 100;
		cout << iter->first << " " << x << endl;
		
	}
	return 0;
}
