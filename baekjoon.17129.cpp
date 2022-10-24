#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[3002][3002];
int vis[3002][3002];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int n,m;
int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    queue <pair<int,int>> Q;
    memset(vis, -1, sizeof(vis));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '2')
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
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] != -1 || board[nx][ny] == '1') continue;
            if (board[nx][ny] == '3' || board[nx][ny] == '4' || board[nx][ny] == '5')
            {
                cout << "TAK" << "\n" << vis[cur.first][cur.second] + 1;
                return (0);
            }
            Q.push({nx, ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }
    cout << "NIE" << "\n";
}
