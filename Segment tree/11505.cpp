#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, K;
long long arr[1000001];
long long *tree;

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = init(node*2, start, (start+end)/2) * init(node*2+1, (start+end)/2+1, end) % 1000000007;
    }
}

long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) { 
        return 1;
    }
    if (left <= start && end <= right) { 
        return tree[node];
    }
    return sum(node*2, start, (start+end)/2, left, right) * sum(node*2+1, (start+end)/2 + 1, end, left, right) % 1000000007;
}

void update(int node, int start, int end, int idx, long long diff) {
    if (idx < start || idx > end) return;
    if (start == end){
    	tree[node] = diff;
    	return;
    }

    update(node*2, start, (start+end)/2, idx, diff);
    update(node*2 + 1, (start+end)/2 + 1, end, idx, diff);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int h = (int)ceil(log2(N));
    tree = new long long[1<<(h+1)];
    init(1, 0, N-1);

    for (int i = 0; i < M+K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1,0,N-1,b-1,c);
        }
        else if (a == 2) {
            cout << sum(1, 0, N-1, b-1, c-1) << '\n';
        }
    }
    return 0;
}
