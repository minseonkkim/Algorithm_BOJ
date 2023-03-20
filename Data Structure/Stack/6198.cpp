#include <iostream>
#include <stack>
using namespace std;

int buildings[80000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> buildings[i];
		
	stack<int> st;
	int answer = 0;
	for(int i = 0; i < n; i++){
		while(!st.empty() && st.top() <= buildings[i]){
			st.pop();
		}
		answer += st.size();
		st.push(buildings[i]);
	}
	cout << answer;

	return 0;
}
