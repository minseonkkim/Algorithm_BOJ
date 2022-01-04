#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_VERTEX 20001
#define MAX_EDGE 300001 

using namespace std;

// 최소 비용 배열
int d[MAX_VERTEX];

// 간선 정보를 담은 Vector 생성
// index : 시작 노드, value : pair<비용, 도착 노드>
vector<pair<int, int> > edge[MAX_EDGE];

void dijkstra(int start_node) {
    // 시작 노드에서 시작 노드로 가는 비용은 0
    d[start_node] = 0;

    // 시작 노드부터 어느 노드까지의 최소 비용을 제시하는 간선 목록
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start_node));

    while (!pq.empty()) {
        // 비용 값을 음수화 하였으므로 top은 비용이 가장 작은 값
        int current = pq.top().second;
        int start_to_current_distance = -pq.top().first;
        pq.pop();

        // 최소 비용 배열에 있는 시작 노드부터 현재 노드까지의 비용보다
        // pq의 top에서 뽑은 시작 노드부터 현재 노드까지의 비용이 더 크면
        // 해당 경로를 통해 인접 노드들을 확인할 필요가 없다.
        if (d[current] < start_to_current_distance) {
            continue;
        }

        // 현재 노드와 연결된 노드들을 모두 검사
        for (int i = 0; i < edge[current].size(); ++i) {
            // 다음 노드 설정
            int next = edge[current][i].second;
            // 시작 노드에서 다음 노드까지의 비용
            // : 시작 노드에서 현재 노드까지의 비용 + 현재 노드에서 i번째로 인접한 노드까지의 비용
            int start_to_next_distance = start_to_current_distance + edge[current][i].first;

            // 기존의 시작 노드에서 다음 노드까지의 최소 비용보다
            // 새롭게 계산된 시작 노드에서 다음 노드까지의 비용이 더 적다면
            // 최소 비용 업데이트
            if (d[next] > start_to_next_distance) {
                d[next] = start_to_next_distance;

                // 갱신된 경로가 최소 비용임을 주장하기 위해 우선순위 큐에 해당 경로 삽입
                pq.push(make_pair(-start_to_next_distance, next));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    int start_node;
    cin >> start_node;

    for (int i = 1; i < v + 1; ++i) {
        d[i] = INF;
    }

    for (int i = 0; i < e; ++i) {
        int start, end, cost;
        cin >> start >> end >> cost;
        edge[start].push_back(make_pair(cost, end));
    }

    dijkstra(start_node);

    for (int i = 1; i < v + 1; ++i) {
        if (d[i] == INF) {
            cout << "INF" << "\n";
        }
        else {
            cout << d[i] << "\n";
        }
    }

    return 0;
}
