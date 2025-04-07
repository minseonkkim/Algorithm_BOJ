#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> selected;

void dfs(int idx){
	if(selected.size() == 6){
		for(int i = 0; i < 6; i++){
			cout << selected[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for(int i = idx; i < nums.size(); i++){
		selected.push_back(nums[i]);
		dfs(i + 1);
		selected.pop_back();
	}
}

int main() {
	while(true){
		int k;
		cin >> k;
		if(k == 0) break;
		nums.clear();
		selected.clear();
		for(int i = 0; i < k; i++){
			int num;
			cin >> num;
			nums.push_back(num);
		}
		dfs(0);
		cout << '\n';
	}
	return 0;
}
