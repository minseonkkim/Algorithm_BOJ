#include <iostream>
using namespace std;

struct Trie {
	Trie *node[26];

	Trie() {
		for (int i = 0; i < 26; i++) node[i] = NULL;
	}

	void insert(string& str, int idx) {
		if (idx == str.size()) return;

		if (node[str[idx] - 'a'] == NULL)
			node[str[idx] - 'a'] = new Trie();

		node[str[idx] - 'a']->insert(str, idx + 1);
	}

	bool find(string& str, int idx) {
		if (idx == str.size()) return true;

		if (node[str[idx] - 'a'] == NULL) return false;

		return node[str[idx] - 'a']->find(str, idx + 1);
	}
};


int main() {
	int n, m;
	cin >> n >> m;

	Trie* root = new Trie();

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		root->insert(str, 0);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;

		if (root->find(str, 0)) ans++;
	}

	cout << ans << '\n';
}
