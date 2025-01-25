#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a;
vector<int> b;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		a.push_back(num);
	}
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		b.push_back(num);
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		answer += a[i] * b[i];
	}
	cout << answer;
	return 0;
}
