#include <iostream>
using namespace std;

int preOrder[1001];
int inOrder[1001];
int Index[1001];

void getPostOrder(int inStart, int inEnd, int preStart, int preEnd){
	if(inStart > inEnd || preStart > preEnd) return;
	
	int rootIndex = Index[preOrder[preStart]];
	int leftSize = rootIndex - inStart;
	int rightSize = inEnd - rootIndex;
	
	getPostOrder(inStart, rootIndex - 1, preStart + 1, preEnd + leftSize);
	getPostOrder(rootIndex + 1, inEnd, preStart + leftSize + 1, preEnd);
	cout << inOrder[rootIndex] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	for(int j = 0; j < t; j++){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> preOrder[i];
		for(int i = 1; i <= n; i++){
			cin >> inOrder[i];
			Index[inOrder[i]] = i;
		}
		getPostOrder(1, n, 1, n);
		cout << '\n';
	}
	return 0;
}
