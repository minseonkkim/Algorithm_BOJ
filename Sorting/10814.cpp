#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,string> a, pair<int,string> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	pair<int, string> tmp;
	vector<pair<int, string>> arr;

	for (int i = 0; i < n; i++) {
		cin >> tmp.first >> tmp.second;
		arr.push_back(tmp);
	}

	stable_sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].first << " " << arr[i].second << '\n';
	}
	return 0;
}
