#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int>> home;
vector<int> selected;
int answer = 987654321;

int getdistance(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(int idx){
	if(selected.size() == k){
		int maxdis = 0;
		for(int i = 0; i < n; i++){
			int mindis = 987654321;
			for(int j = 0; j < selected.size(); j++){
				int index = selected[j];
				mindis = min(mindis, getdistance(home[index].first, home[index].second, home[i].first, home[i].second));
			}
			maxdis = max(maxdis, mindis);
		}
		answer = min(answer, maxdis);
		return;
	}
	
	for(int i = idx; i < n; i++){
		selected.push_back(i);
		dfs(i + 1);
		selected.pop_back();
	}
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		home.push_back({x, y});
	}
	
	dfs(0);
	cout << answer;
	return 0;
}
