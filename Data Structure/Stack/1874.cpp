#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int arr[100000];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<char> ans;
	stack<int> st;
	st.push(1);
	int num = 2;
	int i = 0;
	ans.push_back('+');
	while(i < n){
		if(st.empty() || st.top() < arr[i]){
			st.push(num);
			num++;
			ans.push_back('+');
		} else if(st.top() == arr[i]){
			st.pop();
			ans.push_back('-');
			i++;
		} else{
			cout << "NO";
			return 0;
		}
	}
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << '\n';
	}
	return 0;
}
