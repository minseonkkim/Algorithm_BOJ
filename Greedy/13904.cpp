#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	int arr[1001] = {0, };
	for(int i = 0; i < n; i++){
		int d, w;
		cin >> d >> w;
		v.push_back({w, d});
	}
	sort(v.begin(), v.end(), greater<>());
	int sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = v[i].second; j >= 1; j--){
			if(arr[j] == 0){
				arr[j] = v[i].first;
				sum += v[i].first;
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
