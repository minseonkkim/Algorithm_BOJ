#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int arr[100001];
int *tree;

int minIndex(int x, int y){
	if(arr[x] == arr[y]) return x < y ? x : y;
	return arr[x] < arr[y]? x : y;
}

int init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = start;
    }
    else {
        return tree[node] = minIndex(init(node*2, start, (start+end)/2), init(node*2+1, (start+end)/2+1, end));
    }
}

int update(int node, int start, int end, int idx) {
    if (idx < start || idx > end || start == end) return tree[node];
    return tree[node] = minIndex(update(node*2, start, (start+end)/2, idx), update(node*2+1, (start+end)/2 + 1, end, idx));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int h = (int)ceil(log2(n));
	tree = new int[1 << (h + 1)];
	init(1, 0, n - 1);

	cin >> m;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		
		if(x == 1){
			int a, b;
			cin >> a >> b;
			arr[a - 1] = b;
			update(1, 0, n - 1, a - 1);
		} else if(x == 2){
			cout << tree[1] + 1 << '\n';
		}
	}
	return 0;
}
