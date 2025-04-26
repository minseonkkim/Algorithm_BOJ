#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	vector<string> list;
	for(int i = 0; i < str.length(); i++){
		list.push_back(str.substr(i));
	}
	sort(list.begin(), list.end());
	for(int i = 0; i < list.size(); i++){
		cout << list[i] << '\n';
	}
	return 0;
}
