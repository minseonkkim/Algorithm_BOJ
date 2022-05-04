#include <iostream>
#include <cmath>
using namespace std;

long long arr[100001];
long long *tree;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    init(2 * node, start, (start + end) / 2);
    init(2 * node + 1, (start + end) / 2 + 1, end);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    return;
}

int findMin(int node, int start, int end, int left, int right){
	if(left > end || right < start) return 1111111111;
	else if(left <= start && end <= right) return tree[node];
	
	int a = findMin(2 * node, start, (start + end) / 2, left, right);
	int b = findMin(2 * node + 1, (start + end) / 2 + 1, end, left, right);
	return min(a, b);
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int h = (int)ceil(log2(n));
    tree = new long long[1<<(h + 1)];
    init(1, 0, n - 1);
    
    int left, right;
    for(int i = 0; i < m; i++){
    	cin >> left >> right;
    	cout << findMin(1, 0, n - 1, left - 1, right - 1) << "\n";
    }
    
	return 0;
}
