#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[202][202];
int vis[202][202];

int dx[] = {-2,-2,0,0,2,2};
int dy[] = {-1,1,-2,2,-1,1};

int N,s_x,s_y,e_x,e_y;

queue <pair<int,int>> Q;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> s_x >> s_y >> e_x >> e_y;
    memset(vis, -1, sizeof(vis));
    vis[s_x][s_y] = 0;
    Q.push({s_x,s_y});
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 6; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny] >= 0) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    cout << vis[e_x][e_y];
}
