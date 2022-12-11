#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[102][102];
int vis[102][102];

int dx[] = {2,2,-2,-2,1,1,-1,-1};
int dy[] = {1,-1,1,-1,2,-2,2,-2};

int N,M,e_x,e_y;

int main(void)
{
    cin >> N >> M >> e_x >> e_y;
    queue <pair<int,int>> Q;
    memset(vis, -1, sizeof(vis));
    Q.push({1,1});
    vis[1][1] = 0;
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 8; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (vis[nx][ny] >= 0) continue;
            if (e_x == nx && e_y == ny)
            {
                cout << vis[cur.first][cur.second] + 1;
                return (0);
            }
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    cout << "NEVAR" << "\n";
}
