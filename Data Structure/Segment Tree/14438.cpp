#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
long long arr[100001];
long long *tree;

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = min(init(node*2, start, (start+end)/2), init(node*2+1, (start+end)/2+1, end));
    }
}

long long query(int node, int start, int end, int left, int right){
	if(left > end || right < start) return 1000000001;
	if(left <= start && end <= right) return tree[node];
	return min(query(node * 2, start, (start + end)/2, left, right), query(node * 2 + 1, (start+end)/2 + 1, end, left, right));
}

long long update(int node, int start, int end, int idx, int val) {
    if(idx < start || idx > end) return tree[node];
    if(start == end) return tree[node] = val;
    return tree[node] = min(update(node*2, start, (start+end)/2, idx, val), update(node*2+1, (start+end)/2 + 1, end, idx, val));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int h = (int)ceil(log2(n));
	tree = new long long[1 << (h + 1)];
	init(1, 0, n - 1);

	cin >> m;
	for(int i = 0; i < m; i++){
		int x, a, b;
		cin >> x >> a >> b;
		
		if(x == 1){
			arr[a - 1] = b;
			update(1, 0, n - 1, a - 1, b);
		} else if(x == 2){
			cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';
		}
	}
	return 0;
}
