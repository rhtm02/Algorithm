#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int board[101][101];
int visited[101][101];

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

void dfs(int r,int c,int n, int count){
    board[r][c] = count;
    visited[r][c] = 1;
    
    for (int i=0;i<4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (0<=nr && nr<n && 0<=nc && nr<n){
            if (board[nr][nc] && !visited[nr][nc]){
                dfs(nr,nc,n,count);
            }
        }
    }
}

int bfs(int count, int n){
    queue<pair <int,int>> q;
    for (int r=0;r<n;r++){
        for (int c=0;c<n;c++){
            if (board[r][c] == count){
                visited[r][c] = 1;
                q.push(make_pair(r, c));
            }
        }
    }
    
    int distance = 0;
    
    while (!q.empty()){
        int q_size = q.size();
        for (int i=0;i<q_size;i++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (int j=0;j<4;j++){
                int nr = r + dr[j];
                int nc = c + dc[j];
                if (0<=nr && nr<n && 0<=nc && nc<n){
                    if (board[nr][nc] && board[nr][nc] != count)
                        return distance;
                    
                    else if (!board[nr][nc] && !visited[nr][nc]){
                        visited[nr][nc] = 1;
                        q.push(make_pair(nr,nc));
                    }         
                }
            }
        }
        distance++;
    }
    return 0;
}

int main(int argc, const char * argv[]) {

    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    
    int count = 1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (board[i][j] && !visited[i][j]){
                dfs(i,j,n,count++);
            }
        }
    }
    
    int result = 987654321;
    
    for (int i=1;i<count;i++){
        memset(visited, 0, sizeof(visited));
        result = min(result ,bfs(i,n));
    }
    
    cout << result << "\n";
    return 0;
}