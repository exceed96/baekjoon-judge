#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[1002][1002];
int vis[1002][1002];

int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};

int m,n;

queue <pair<int,int>> Q;
int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    memset(vis, -1, sizeof(vis));
    cin >> m >> n;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'z')
            {
                Q.push({i,j});
                vis[i][j] = 0;
            }
        }
    }
    
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 8; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == 'x' || vis[nx][ny] >= 0) continue;
            if (board[nx][ny] == 'n')
            {
                cout << vis[cur.first][cur.second] + 1;
                return (0);
            }
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    cout << "NIE\n";
}
