#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int arr[100000];
int *even_tree, *odd_tree;

void init(int node, int start, int end){
	if(start == end){
		if(arr[start] % 2 == 0) {
			even_tree[node] = 1;
			odd_tree[node] = 0;
		} else {
			even_tree[node] = 0;
			odd_tree[node] = 1;
		}
		return;
	}
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	even_tree[node] = even_tree[node * 2] + even_tree[node * 2 + 1];
	odd_tree[node] = odd_tree[node * 2] + odd_tree[node * 2 + 1];
	return;
}

int even_update(int node, int start, int end, int idx, int val){
	if(idx < start || idx > end) return even_tree[node];
	if(start == end) return even_tree[node] = val;
	return even_tree[node] = even_update(node * 2, start, (start + end) / 2, idx, val) + even_update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
}

int odd_update(int node, int start, int end, int idx, int val){
	if(idx < start || idx > end) return odd_tree[node];
	if(start == end) return odd_tree[node] = val;
	return odd_tree[node] = odd_update(node * 2, start, (start + end) / 2, idx, val) + odd_update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
}

int findEven(int node, int start, int end, int left, int right){
	if(left > end || right < start) return 0;
	else if(left <= start && right >= end){
		return even_tree[node];
	} else{
		return findEven(node * 2, start, (start + end) / 2, left, right) + findEven(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}
}

int findOdd(int node, int start, int end, int left, int right){
	if(left > end || right < start) return 0;
	else if(left <= start && right >= end){
		return odd_tree[node];
	} else{
		return findOdd(node * 2, start, (start + end) / 2, left, right) + findOdd(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++)	cin >> arr[i];
	
	int h = (int) ceil(log2(n));
	even_tree = new int[(1 << (h + 1))];
	odd_tree = new int[(1 << (h + 1))];
	
	init(1, 0, n - 1);
	
	cin >> m;
	for(int i = 0; i < m; i++){
		int com, a, b;
		cin >> com >> a >> b;
		if(com == 1) {
			if(b % 2 == 0){
				even_update(1, 0, n - 1, a - 1, 1);
				odd_update(1, 0, n - 1, a - 1, 0);
			} else{
			 	even_update(1, 0, n - 1, a - 1, 0);
				odd_update(1, 0, n - 1, a - 1, 1);
			}
		}
		else if(com == 2) cout << findEven(1, 0, n - 1, a - 1, b - 1) << '\n';
		else if(com == 3) cout << findOdd(1, 0, n - 1, a - 1, b - 1) << '\n';
	}
	
	return 0;
}
