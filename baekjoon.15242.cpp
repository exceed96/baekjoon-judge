#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[10][10];
int vis[10][10];

int dx[] = {2,2,-2,-2,1,1,-1,-1};
int dy[] = {1,-1,1,-1,2,-2,2,-2};

int s_x,s_y,e_x,e_y;

int main(void)
{
    memset(vis, -1, sizeof(vis));
    queue <pair<int,int>> Q;
    string s,e;
    cin >> s >> e;
    s_x = s[0] - 96; s_y = s[1] - 48; e_x = e[0] - 96; e_y = e[1] - 48;
    Q.push({s_x,s_y});
    vis[s_x][s_y] = 0;
    if (s_x == e_x && s_y == e_y)
    {
        cout << 0;
        return (0);
    }
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 8; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
            if (nx == e_x && ny == e_y)
            {
                cout << vis[cur.first][cur.second] + 1;
                return (0);
            }
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
}
