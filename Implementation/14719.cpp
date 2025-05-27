#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<int> v;
	for(int i = 0; i < w; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	int answer = 0;
	for(int i = 1; i < w - 1; i++){
		int ml = 0, mr = 0;
		for(int j = 0; j < i; j++) ml = max(ml, v[j]);
		for(int j = i + 1; j < w; j++) mr = max(mr, v[j]);
		if(min(ml, mr) - v[i] > 0) answer += (min(ml, mr) - v[i]);
	}
	cout << answer;
	return 0;
}
