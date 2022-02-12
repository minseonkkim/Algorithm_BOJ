#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

int n, k;
int arr[MAX] = {0, };
bool visited[MAX] = { false, };
queue<int> q;

void bfs(){
	arr[n] = 0;
	visited[n] = true;
	q.push(n);
	
	while(!q.empty()){
		int node = q.front();
		if(node == k) break;
		q.pop();
		
		if(visited[node + 1] == false && node + 1 >= 0 && node + 1 < MAX){
			visited[node + 1] = true;
			q.push(node + 1);
			arr[node + 1] = arr[node] + 1;
		}
		
		if(visited[node - 1] == false && node - 1 >= 0 && node - 1 < MAX){
			visited[node - 1] = true;
			q.push(node - 1);
			arr[node - 1] = arr[node] + 1;
		}
		
		if(visited[node * 2] == false && node * 2 >= 0 && node * 2 < MAX){
			visited[node * 2] = true;
			q.push(node * 2);
			arr[node * 2] = arr[node] + 1;
		}
	}
}

int main() {
	cin >> n >> k;
	bfs();
	cout << arr[k];
}
