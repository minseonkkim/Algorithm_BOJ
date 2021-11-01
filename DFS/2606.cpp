#include <iostream>
using namespace std;

int map[101][101];
int visit[101];
int com, cnt;

void num_of_virus_com(int node) {
    visit[node] = 1;

    for (int i = 1; i <= com; i++) {
        if (!visit[i] && map[node][i] == 1) {
            cnt++;
            num_of_virus_com(i);
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

    num_of_virus_com(1);
    cout << cnt << endl;

    return 0;
}
