#include <iostream>
#include <string>
using namespace std;

int cnt;
string str, pat;
int failure[100000];

void fail() {
	int j;
	int len = pat.length();

	failure[0] = -1;
	for (int i = 1; i < len; i++) {
		j = failure[i - 1];

		while (j >= 0 && (pat[i] != pat[j + 1]))
			j = failure[j];

		if (pat[i] == pat[j + 1]) failure[i] = j + 1;
		else failure[i] = -1;
	}
}

void kmp() {
	int i = 0, j = 0;
	int lenr = str.length();
	int lenp = pat.length();

	for (int i = 0; i < lenr; i++) {
		while (j > 0 && str[i] != pat[j]) j = failure[j - 1] + 1;
		if (str[i] == pat[j]) j++;
		if (j == lenp) {
			cnt++;
			j = failure[j - 1] + 1;
		}
	}
}

int main() {
	getline(cin, pat);
	getline(cin, str);
	str.append(str);
	str.pop_back();
	fail();
	kmp();
	cout << cnt;
}
