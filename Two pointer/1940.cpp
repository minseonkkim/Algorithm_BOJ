#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> ingredient;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		ingredient.push_back(x);
	}
	sort(ingredient.begin(), ingredient.end());
	int l = 0, r = n - 1, answer = 0;
	while(l < r){
		if(ingredient[l] + ingredient[r] < m) l++;
		else if(ingredient[l] + ingredient[r] == m){
			answer++;
			l++;
			r--;
		}
		else r--;
	}
	cout << answer;
	return 0;
}
