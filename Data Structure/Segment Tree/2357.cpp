#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int arr[100000];
int *min_tree, *max_tree;

void init(int node, int start, int end){
	if(start == end){
		min_tree[node] = arr[start];
		max_tree[node] = arr[start];
		return;
	}
	init(2 * node, start, (start + end) / 2);
	init(2 * node + 1, (start + end) / 2 + 1, end);
	min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
	return;
}

pair<int, int> findMinMax(int node, int start, int end, int left, int right){
	if(left > end || right < start){
		return {INT_MAX, 0};
	} else if(left <= start && right >= end){
		return {min_tree[node], max_tree[node]};
	} else{
		pair<int, int> l = findMinMax(node * 2, start, (start + end) / 2, left, right);
		pair<int, int> r = findMinMax(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
		return {min(l.first, r.first), max(l.second, r.second)};
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int h = (int)ceil(log2(n));
	min_tree = new int[1 << (h + 1)];
	max_tree = new int[1 << (h + 1)];
	
	init(1, 0, n - 1);
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		pair<int, int> ret = findMinMax(1, 0, n - 1, a - 1, b - 1);
		cout << ret.first << " " << ret.second << '\n';
	}
	return 0;
}
