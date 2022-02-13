#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(int a, int b){
	return a > b;
}

int main() {
	int n, m, p, res = 0;
	vector<int> book_l;
	vector<int> book_r;
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> p;
		if(p < 0) book_l.push_back(p);
		else book_r.push_back(p);
	}
	
	sort(book_l.begin(), book_l.end());
	sort(book_r.begin(), book_r.end(), compare);
	
	for(int i = 0; i < book_l.size(); i += m){
		res += abs(book_l[i]) * 2;
	}
	for(int i = 0; i < book_r.size(); i += m){
		res += book_r[i] * 2;
	}
	
	if(book_l.empty()) res -= book_r[0];
	else if(book_r.empty()) res -= abs(book_l[0]);
	else if(abs(book_l[0]) > book_r[0]) res -= abs(book_l[0]);
	else res -= book_r[0];
	
	cout << res << endl;
	return 0;
}
