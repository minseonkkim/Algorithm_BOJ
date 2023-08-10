#include <iostream>
#include <queue>
#define max_int 21
#define max_val 401
using namespace std;

int n, a[max_int][max_int], check[max_int][max_int];
int shark_x, shark_y, eat_cnt, shark_size = 2;
int min_dist, min_x, min_y, result;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void init(){
    min_dist = max_val;
    min_x = max_int;
    min_y = max_int;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            check[i][j] = -1;
        }
    }
}


void bfs(int x, int y){
    queue<pair<int, int>> q;
    check[x][y] = 0;
    q.push({x, y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(check[nx][ny] != -1 || a[nx][ny] > shark_size) continue;
            
            check[nx][ny] = check[x][y] + 1;
            
            if(a[nx][ny] != 0 && a[nx][ny] < shark_size){
                if(min_dist > check[nx][ny]){
                    min_x = nx;
                    min_y = ny;
                    min_dist = check[nx][ny];
                } else if(min_dist == check[nx][ny]){
                    if(min_x == nx){
                        if(min_y > ny){
                            min_x = nx;
                            min_y = ny;
                        }
                    } else if(min_x > nx){
                        min_x = nx;
                        min_y = ny;
                    }
                }
            }
            
            q.push({nx, ny});
        }
    }
}

int main(){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            
            if(a[i][j] == 9){
                shark_x = i;
                shark_y = j;
                a[i][j] = 0;
            }
        }
    }
   
    while(true){
        init();
        bfs(shark_x, shark_y);
        
        if(min_x != max_int && min_y != max_int){
            result += check[min_x][min_y];
            eat_cnt++;
            
            if(eat_cnt == shark_size){
                shark_size++;
                eat_cnt = 0;
            }
          
            a[min_x][min_y] = 0;
            
            shark_x = min_x;
            shark_y = min_y;
        } else{
            break;
        }
    }
    
    cout << result << endl;
}
