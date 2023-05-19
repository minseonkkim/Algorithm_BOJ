#include <iostream>
#include <cmath>
using namespace std;

int n, q;
long long arr[100001];
long long *tree;

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
    }
}

long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) { 
        return 0;
    }
    if (left <= start && end <= right) { 
        return tree[node];
    }
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2 + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff) {
    if (idx < start || idx > end) return;
    tree[node] += diff;
    if (start != end) {
        update(node*2, start, (start+end)/2, idx, diff);
        update(node*2+1, (start+end)/2 + 1, end, idx, diff);
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int h = (int)ceil(log2(n));
	tree = new long long[1 << (h + 1)];
	init(1, 0, n - 1);
	
	for(int i = 0; i < q; i++){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if(x > y){
			int tmp = x;
			x = y;
			y = tmp;
		}
		cout << sum(1, 0, n - 1, x - 1, y - 1) << '\n';
		long long diff = b - arr[a - 1];
		arr[a - 1] = b;
		update(1, 0, n - 1, a - 1, diff);
	}
	return 0;
}
