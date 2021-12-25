#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	queue<int> q;
	for(int i = 1; i <= n; i++){
		q.push_back(i);
	}
	
	cout << "<";
	
	while(true){
		if(q.empty()) break;
		for(int i = 1; i <= k; i++){
			if(i != k){
				int t = q.front();
				q.pop();
				q.push(t);
			}
			else{
				cout << q.front();
				q.pop();
				if(!Q.empty()) cout << ", ";
			}
		}
	}
	cout << ">";
	
	return 0;
}
