#include <iostream>
#include <queue>

using namespace std;

int board[1002][1002];
int vis[1002][1002];
bool vis2[1002][1002];
int N,M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M;

    queue <pair<int,int>> Q;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 2)
            {
                vis2[i][j] = 1;
                vis[i][j] = 0;
                Q.push({i,j});
            }
            if(board[i][j] == 1)
                vis[i][j] = -1;
        }
    
    while(!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(!board[nx][ny] || vis2[nx][ny]) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            vis2[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cout << vis[i][j] << " ";
        cout << "\n";
    }
}
