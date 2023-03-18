#include <iostream>
using namespace std;

int Index[100001];
int inOrder[100001];
int postOrder[100001];

void getPreOrder(int inStart, int inEnd, int postStart, int postEnd){
	if(inStart > inEnd || postStart > postEnd) return;
	
	int rootIndex = Index[postOrder[postEnd]];
	int leftSize = rootIndex - inStart;
	int rightSize = inEnd - rootIndex;
	
	cout << inOrder[rootIndex] << ' ';
	getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
	getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> inOrder[i];
		Index[inOrder[i]] = i;
	}
	for(int i = 1; i <= n; i++) 
		cin >> postOrder[i];
	
	getPreOrder(1, n, 1, n);
	return 0;
}
