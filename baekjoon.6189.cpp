#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[102][102];
int vis[102][102];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int R,C;

queue <pair<int,int>> Q;

int main(void)
{
    memset(vis, -1, sizeof(vis));
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'B')
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
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (board[nx][ny] == '*' || vis[nx][ny] >= 0) continue;
            if (board[nx][ny] == 'C')
            {
                cout << vis[cur.first][cur.second] + 1;
                return (0);
            }
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
}
