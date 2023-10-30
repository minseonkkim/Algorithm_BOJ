#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;

bool isZero(string s){
	vector<int> num;
	vector<char> op;
	
	string tmp;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '+' || s[i] == '-'){
			num.push_back(stoi(tmp));
			op.push_back(s[i]);
			tmp = "";
		} else if(s[i] != ' '){
			tmp += s[i];
		}
	}
	num.push_back(stoi(tmp));
	
	int sum = num[0];
	for(int i = 1; i < num.size(); i++){
		if(op[i - 1] == '+'){
			sum += num[i];
		} else{
			sum -= num[i];
		}
	}
	if(sum == 0) return true;
	else return false;
}

void dfs(int idx, string expression){
	if(idx == n + 1){
		if(isZero(expression)){
			cout << expression << '\n';
		}
		return;
	}
	
	dfs(idx + 1,  expression + " " + to_string(idx));
	dfs(idx + 1, expression + "+" + to_string(idx));
	dfs(idx + 1, expression + "-" + to_string(idx));
}

int main() {
	int t;
	cin >> t;
	for(int test_case = 0; test_case < t; test_case++){
		cin >> n;
		dfs(2, "1");
		cout << '\n';
	}
	return 0;
}
