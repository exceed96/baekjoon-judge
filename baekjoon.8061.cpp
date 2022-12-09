#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[190][190];
int vis[190][190];

int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

int N,M;

queue <pair<int,int>> Q;

int main(void)
{
    cin >> N >> M;
    memset(vis, -1, sizeof(vis));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '1')
            {
                Q.push({i,j});
                vis[i][j] = 0;
            }
        }
    }
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == '1' || vis[nx][ny] >= 1) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
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
