#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[7][7];
int vis[7][7];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int s_x,s_y;

int main(void)
{
    for(int i = 0; i < 5 ; i++)
        for(int j = 0; j < 5; j++)
            cin >> board[i][j];
            
    memset(vis, -1, sizeof(vis));
    cin >> s_x >> s_y;
    queue <pair<int,int>> Q;
    Q.push({s_x,s_y});
    vis[s_x][s_y] = 0;
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (vis[nx][ny] >= 0 || board[nx][ny] == -1) continue;
            if (board[nx][ny] == 1)
            {
                cout << vis[cur.first][cur.second] + 1;
                return (0);
            }
            Q.push({nx,ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }
    cout << -1;
}
