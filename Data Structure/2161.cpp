#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	queue<int> q;
	for(int i = 1; i <= n; i++){
		q.push(i);
	}
	
	while(q.size() != 1){
		cout << q.front() << " ";
		q.pop();
		int t = q.front();
		q.pop();
		q.push(t);
	}
	cout << q.front();
	
	return 0;
}
