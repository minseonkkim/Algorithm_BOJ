#include <iostream>
#include <queue>
using namespace std;

int r, c;
char arr[250][250];
bool visited[250][250];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int cs = 0, cw = 0;

void bfs(int a, int b){
	int ts = 0, tw = 0;
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b] = true;
	if(arr[a][b] == 'v') tw++;
	else ts++;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!(nx >= 0 && nx < r && ny >= 0 && ny < c)) continue;
			
			if(!visited[nx][ny] && arr[nx][ny] != '#'){
				if(arr[nx][ny] == 'v') tw++;
				else if(arr[nx][ny] == 'o') ts++;
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
	
	if(tw >= ts) cw += tw;
	else if(ts > tw) cs += ts;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if((arr[i][j] == 'o' || arr[i][j] == 'v') && !visited[i][j]){
				bfs(i, j);
			}
		}
	}
	
	cout << cs << " " << cw << endl;
	return 0;
}
