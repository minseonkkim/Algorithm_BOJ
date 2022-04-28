#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	return a.second > b.second;
}

int main(){
	int score;
	vector<pair<int, int>> v;
	for(int i = 0; i < 8; i++){
		cin >> score;
		v.push_back({i + 1, score});
	}
	sort(v.begin(), v.end(), compare);
	int sum = 0;
	vector<int> hs;
	for(int i = 0; i < 5; i++){
		sum += v[i].second;
		hs.push_back(v[i].first);
	}
	cout << sum << endl;
	sort(hs.begin(), hs.end());
	for(int i = 0; i < hs.size(); i++){
		cout << hs[i] << " ";
	}
}
