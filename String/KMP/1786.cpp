#include <iostream>
#include <string>
#include <vector>
using namespace std;

int failure[1000001];
vector<int> ans;

void fail(string pat) {
	int j;  // 접미부의 비교점
	int n = pat.length();

	failure[0] = -1;
	for (int i = 1; i < n; i++) {  // 접두부의 비교점
		j = failure[i - 1];

		while ((pat[j + 1] != pat[i]) && (j >= 0)) {
			j = failure[j];
		}

		if (pat[i] == pat[j + 1]) {
			failure[i] = j + 1;
		}
		else {
			failure[i] = -1;
		}
	}
}

void kmp(string str, string pat) {
	int j = 0;  // pat 인덱스
	int lens = str.length();
	int lenp = pat.length();

	for (int i = 0; i < lens; i++) { // str 인덱스
		while (j > 0 && str[i] != pat[j]) j = failure[j - 1] + 1;
		if (str[i] == pat[j]) j++;
		if (j == lenp) {
			ans.push_back(i - lenp + 2);
			j = failure[j - 1] + 1;
		}
	}
}

int main()
{
	string t, p;
	getline(cin, t);
	getline(cin, p);

	fail(p);
	kmp(t, p);

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}
