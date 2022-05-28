#include <iostream>
#include <stack>
#define MAX 1001
using namespace std;

int N;
stack<int> adj[MAX];
int edges[MAX][MAX];
int degree[MAX];

void dfs(int n) {
    while (!adj[n].empty()) {
        int next = adj[n].top();
        adj[n].pop();
        if (edges[n][next] && edges[next][n]) {
            edges[n][next]--;
            edges[next][n]--;
            dfs(next);
        }
    }
    cout << n << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            int x;
            cin >> x;
            while (x--) {
                adj[i].push(j);
                edges[i][j]++;
                degree[j]++;
            }
        }
    }
    
    // 간선 홀수 개 있으면 오일러 회로 완성 불가
    for (int i = 1; i < N + 1; i++) {
        if (degree[i] % 2 != 0) {
            cout << -1;
            return 0;
        }
    }

    dfs(1);

    return 0;
}
