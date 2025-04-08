#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	vector<Node*> children;
};

int idx;

vector<string> split(string& str){
	vector<string> res;
	string token;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == ' '){
			res.push_back(token);
			token = "";
		} else{
			token += str[i];
		}
	}
	res.push_back(token);
	return res;
}

Node* buildTree(vector<string>& tokens){
	string cur = tokens[idx++];
	if(cur == "#") return nullptr;
	
	Node* node = new Node();
	
	while(true){
		if(tokens[idx] == "#"){
			idx++;
			break;
		}
		Node* child = buildTree(tokens);
		node->children.push_back(child);
	}
	return node;
}

string getStructure(Node* node){
	if(node == nullptr) return "";
	vector<string> subs;
	for(int i = 0; i < node->children.size(); i++){
		subs.push_back(getStructure(node->children[i]));
	}
	sort(subs.begin(), subs.end());
	string res = "(";
	for(int i = 0 ; i < subs.size(); i++){
		res += subs[i];
	}
	res += ")";
	return res;
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	for(int test_case = 0; test_case < t; test_case++){
		string line1, line2;
		getline(cin, line1);
		getline(cin, line2);
		
		vector<string> tokens1 = split(line1);
		vector<string> tokens2 = split(line2);
		
		idx = 0;
		Node* root1 = buildTree(tokens1);
		idx = 0;
		Node* root2 = buildTree(tokens2);
		
		string struct1 = getStructure(root1);
		string struct2 = getStructure(root2);
		
		if(struct1 == struct2){
			cout << "The two trees are isomorphic." << endl;
        } else {
            cout << "The two trees are not isomorphic." << endl;
        }
	}
	return 0;
}
