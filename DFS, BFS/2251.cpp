#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int a, b, c;
bool visited[201][201][201];
vector<int> answer;

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, c });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		if (visited[x][y][z]) continue;
		visited[x][y][z] = true;

		if (x == 0) answer.push_back(z);

		// a -> b
		if (x + y <= b) q.push({ {0, x + y}, z });
		else q.push({ {x - (b - y), b},  z});

		// c -> b
		if (y + z <= b) q.push({{ x, y + z }, 0});
		else q.push({ {x, b}, z - (b - y) });

		// a -> c
		if (x + z <= c) q.push({ {0, y}, x + z });
		else q.push({ {x - (c - z), y}, c });

		// b -> c
		if (y + z <= c) q.push({ {x, 0}, y + z });
		else q.push({ {x, y - (c - z)}, c });

		// b -> a
		if (x + y <= a) q.push({ {x + y, 0}, z });
		else q.push({ {a, y - (a - x)}, z });

		// c -> a
		if (x + z <= a) q.push({ {x + z, y}, 0 });
		else q.push({ {a, y}, z - (a - x) });
	}
}

int main()
{
	cin >> a >> b >> c;
	bfs();
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}
