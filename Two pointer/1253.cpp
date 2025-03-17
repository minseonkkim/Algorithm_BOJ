#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> num;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		num.push_back(x);
	}
	
	sort(num.begin(), num.end());
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		int cur = num[i];
		
		int l = 0, r = n - 1;
		while(l < r){
			if(l == i){
				l++;
				continue;
			} else if(r == i){
				r--;
				continue;
			}
			int sum = num[l] + num[r];
			if(sum == cur){
				answer++;
				break;
			} else if(sum > cur) r--;
			else l++;
		}
	}
	cout << answer;
	return 0;
}
