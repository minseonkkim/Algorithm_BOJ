#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> v;
bool visited[15];

void dfs(string str, int start, int len){
	if(len == L){
		int a = 0;
		int b = 0;
		for(int i = 0; i < str.length(); i++){
			if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] =='u') a++;
			else b++;
		}
		if(a >= 1 && b >= 2){
			cout << str << '\n';
		}
		return;
	}
	
	for(int i = start; i < v.size(); i++){
		if(!visited[i]){
			visited[i] = true;
			dfs(str + v[i], i, len + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> L >> C;
	for(int i = 0; i < C; i++){
		char c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	dfs("", 0, 0);
	return 0;
}
