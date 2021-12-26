#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compareWith(string a, string b){
	if(a.length() == b.length())
		return a < b;
	else return a.length() < b.length();
}

int main() {
	int n;
	cin >> n;
	
	string s;
	vector<string> v;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		if(find(v.begin(), v.end(), s) == v.end())
			v.push_back(s);
	}
	
	sort(v.begin(), v.end(), compareWith);
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << "\n";
	}
	return 0;
}
