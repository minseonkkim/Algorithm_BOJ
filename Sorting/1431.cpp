#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> serials;

bool cmp(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	
	int asum = 0; int bsum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '0' && a[i] <= '9') asum += a[i] - '0';
		if (b[i] >= '0' && b[i] <= '9') bsum += b[i] - '0';
	}
	if(asum != bsum) return asum < bsum;
	
	return a < b;
}

int main() {
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		serials.push_back(s);
	}
	sort(serials.begin(), serials.end(), cmp);

	for (int i = 0; i < serials.size(); i++) {
		cout << serials[i] << '\n';
	}
}
