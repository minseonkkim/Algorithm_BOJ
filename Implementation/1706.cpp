#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;
char map[20][20];
vector<string> words;

int main() {
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		string str;
		cin >> str;
		for(int j = 0; j < c; j++){
			map[i][j] = str[j];
		}
	}
	
	for(int i = 0; i < r; i++){
		string word = "";
		for(int j = 0; j < c; j++){
			if(map[i][j] == '#'){
				if(word != "" && word.length() > 1) words.push_back(word);
				word = "";
			} else word += map[i][j];
		}
		if(word != "" && word.length() > 1) words.push_back(word);
	}
	for(int j = 0; j < c; j++){
		string word = "";
		for(int i = 0; i < r; i++){
			if(map[i][j] == '#'){
				if(word != "" && word.length() > 1) words.push_back(word);
				word = "";
			} else word += map[i][j];
		}
		if(word != "" && word.length() > 1) words.push_back(word);
	}
	sort(words.begin(), words.end());
	cout << words[0];
	return 0;
}
