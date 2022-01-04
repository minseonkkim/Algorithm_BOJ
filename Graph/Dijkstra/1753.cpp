#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000 // 시작 노드에서 해당 노드까지의 경로가 없는 경우의 비용
#define MAX_VERTEX 20001 // 최대 vertex 개수
#define MAX_EDGE 300001 // 최대 edge 개수

using namespace std;

// 최소 비용 배열
int d[MAX_VERTEX];

// 간선 정보를 담은 Vector 생성
// index : 시작 노드
// value : pair<비용, 도착 노드> 목록
vector<pair<int, int> > edge[MAX_EDGE];

void dijkstra(int start_node){
    d[start_node] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start_node));

    while(!pq.empty()){
        int current = pq.top().second;
        int start_to_current_distance = -pq.top().first;

        pq.pop();

        if (d[current] < start_to_current_distance){
            continue;
        }

        for (int i=0; i<edge[current].size(); ++i){
            int next = edge[current][i].second;
            int start_to_next_distance = start_to_current_distance + edge[current][i].first;

            if (d[next] > start_to_next_distance){
                d[next] = start_to_next_distance;
                pq.push(make_pair(-start_to_next_distance, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int v, e;
    cin >> v >> e;

    int start_node;
    cin >> start_node;

    for (int i=1; i<v+1; ++i){
        d[i] = INF;
    }

    for (int i=0; i<e; ++i){
        int start, end, cost;
        cin >> start >> end >> cost;
        edge[start].push_back(make_pair(cost, end));
    }

    dijkstra(start_node);

    for (int i=1; i<v+1; ++i){
        if (d[i] == INF){
            cout << "INF" << "\n";    
        }
        else{
            cout << d[i] << "\n";
        }
    }

    return 0;
}
