#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int n;
char arr[100][100];
bool visited[100][100];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void bfs(int a, int b){
    queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b] = true;
 
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
         
            if (visited[nx][ny] == false && arr[nx][ny] == arr[x][y]){
            	visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void bfs2(int a, int b){
 queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b] = true;
 
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
			
			if(arr[x][y] == 'R' || arr[x][y] == 'G') {
				if((arr[nx][ny] == 'R' || arr[nx][ny] == 'G') && !visited[nx][ny]){
					visited[nx][ny] = true;
					q.push({nx, ny});
				}
			}
			if(arr[x][y] == 'B'){
				if(!visited[nx][ny] && arr[nx][ny] == 'B'){
					visited[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
	}
}


int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	int cnt1 = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]) {
				bfs(i, j);
				cnt1++;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	int cnt2 = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]) {
				bfs2(i, j);
				cnt2++;
			}
		}
	}
	cout << cnt1 << " " << cnt2 << endl;
	
	return 0;
}
