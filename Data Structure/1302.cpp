#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, max = 0;
	string str, result;
	map<string, int> m;
	
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> str;
		if(m.find(str) != m.end()){
			m[str]++;
		} else{
			m[str] = 1;
		}
	}

	for(auto it = m.begin(); it != m.end(); it++){
		if(max < it->second){
			max = it->second;
			result = it->first;
		}
	}
	
	cout << result << endl;
	return 0;
}
