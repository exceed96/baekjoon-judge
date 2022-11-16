#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[22][22];
bool vis[22][22];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int W,H;

int main(void)
{
    while (1)
    {
        int result = 1;
        queue <pair<int,int>> Q;
        cin >> W >> H;
        if (!W && !H) break;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == '@')
                {
                    Q.push({i,j});
                    vis[i][j] = 1;
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
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (board[nx][ny] == '#' || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                result++;
                Q.push({nx,ny});
            }
        }
        cout << result << "\n";
    }
}
