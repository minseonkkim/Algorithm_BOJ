#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k, cnt;
int arr[100][100];
bool visited[100][100];
vector<int> v;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(int a, int b){
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b] = true;
	int area = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!(nx >= 0 && ny >= 0 && nx < m && ny < n))
				continue;
				
			if(arr[nx][ny] == 0 && !visited[nx][ny]){
				visited[nx][ny] = true;
				q.push({nx, ny});
				area++;
			}
		}
	}
	v.push_back(area);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m >> n >> k;
	
	for(int i = 0; i < k; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int p = m - y2; p < m - y1; p++){
			for(int q = x1; q < x2; q++){
				arr[p][q] = 1;
			}
		}
	}

	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] == 0 && !visited[i][j]){
				bfs(i, j);
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}
