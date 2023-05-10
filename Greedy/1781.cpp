#include <iostream>
#include <queue>
using namespace std;

struct cmp{
	bool operator()(pair<int, int>&a, pair<int, int>&b){
		if(a.first == b.first){
			return a.second < b.second;
		} else{
			return a.first > b.first;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	priority_queue<int, vector<int>, greater<int>> pqAns;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		pq.push({a, b});
	}
	
	long long answer = 0;
    int time = 1;
	while(!pq.empty()){
		pair<int, int> cur = pq.top();
		pq.pop();
		if(cur.first >= time){
			pqAns.push(cur.second);
			time++;
		} else if(pqAns.top() < cur.second){
			pqAns.pop();
			pqAns.push(cur.second);
		}
	}
	while(!pqAns.empty()){
		answer += pqAns.top();
		pqAns.pop();
	}
	cout << answer << endl;
	return 0;
}
