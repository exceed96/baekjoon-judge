#include <iostream>
#include <queue>

using namespace std;

int board[102][102][102];
int vis[102][102][102];
int m,n,h;
int dx[] = {1,0,-1,0,0,0};
int dy[] = {0,1,0,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> m >> n >> h;
    queue<pair<pair<int,int>,int>> Q;
    for(int k = 0; k < h; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> board[i][j][k];
                if(board[i][j][k] == 1)
                    Q.push(make_pair(make_pair(i,j),k));
                if(!board[i][j][k])
                    vis[i][j][k] = -1;
            }
        }
    }
    while (!Q.empty())
    {
        pair<pair<int,int>,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 6; dir++)
        {
            int nx = cur.first.first + dx[dir];
            int ny = cur.first.second + dy[dir];
            int nz = cur.second + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (vis[nx][ny][nz] >= 0) continue;
            vis[nx][ny][nz] = vis[cur.first.first][cur.first.second][cur.second] + 1;
            Q.push(make_pair(make_pair(nx,ny), nz));
        }
    }
    int res = 0;
    for(int k = 0; k < h; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j][k] == -1)
                {
                    cout << -1;
                    return (0);
                }
                res = max(res, vis[i][j][k]);
            }
        }
    }
    cout << res;
}
