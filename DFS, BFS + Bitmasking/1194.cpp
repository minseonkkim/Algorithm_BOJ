#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<cmath>

#define endl "\n"
#define MAX 50
using namespace std;


int n, m, sx, sy;
char map[MAX][MAX];
bool visited[MAX][MAX][1 << 6];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int bfs(){
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(sx, sy), make_pair(0, 0)));
	visited[sx][sy][0] = true;

	while (q.empty() == 0)
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int Cnt = q.front().second.first;
		int Key = q.front().second.second;
		q.pop();

		if (map[x][y] == '1') return Cnt;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (visited[nx][ny][Key] == false)
				{
					if (map[nx][ny] == '.' || map[nx][ny] == '1')
					{
						visited[nx][ny][Key] = true;
						q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Key)));
					}
					else if ('a' <= map[nx][ny] && map[nx][ny] <= 'f')
					{
						int Tmp_Key = Key | (1 << (int(map[nx][ny] - 'a')));
						visited[nx][ny][Tmp_Key] = true;
						q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Tmp_Key)));
					}
					else if ('A' <= map[nx][ny] && map[nx][ny] <= 'F')
					{
						int exist= Key & (1 << (int(map[nx][ny]) - 'A'));

						if (exist != 0){
							visited[nx][ny][Key] = true;
							q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Key)));
						}
					}
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s; 
		cin >> s;
		for (int j = 0; j < m; j++)
		{

			map[i][j] = s[j];
			if (map[i][j] == '0')
			{
				sx = i;
				sy = j;
				map[i][j] = '.';
			}
		}
	}

	cout << bfs() << endl;

	return 0;
}
