#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> crane, box;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		crane.push_back(x);
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		box.push_back(x);
	}
	
	sort(crane.begin(), crane.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());
	
	if(crane[0] < box[0]){
		cout << -1;
		return 0;
	}
	
	int idx = 0, time = 0;
	while(!box.empty()){
		time++;
		for(int i = 0; i < crane.size(); i++){
			for(int j = 0; j < box.size(); j++){
				if(crane[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}
	cout << time;
	return 0;
}
