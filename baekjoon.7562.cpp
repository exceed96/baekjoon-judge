#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {-2,-1,1,2,-2,-1,1,2};

int vis[302][302];

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int I, s_x, s_y, e_x, e_y;
        queue <pair<int,int>> Q;
        memset(vis, -1, sizeof(vis));
        cin >> I >> s_x >> s_y >> e_x >> e_y;
        vis[s_x][s_y] = 0;
        Q.push({s_x, s_y});
        while (vis[e_x][e_y] == -1)
        {
            pair <int,int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 8; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
                if (vis[nx][ny] != -1) continue;
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                Q.push({nx,ny});
            }
        }
        while (!Q.empty())
            Q.pop();
        cout << vis[e_x][e_y] << "\n";
    }
}
