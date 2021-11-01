#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int visit[101];
int com, cnt;

void num_of_virus_com2(int start) {
    visit[start] = 1;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int i = 1; i <= com; i++) {
            if (!visit[i] && map[node][i] == 1) {
                q.push(i);
                visit[i] = 1;
                cnt++;
            }
        }
    }
}

int main() {
    int n, u, v;
    cin >> com >> n;

    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        map[u][v] = map[v][u] = 1;
    }

    num_of_virus_com2(1);

    cout << cnt << endl;

    return 0;
}
