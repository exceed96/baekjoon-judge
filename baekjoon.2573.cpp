#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[302][302];
bool vis[302][302];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N,M, t = 0, count = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    for( ; ; t++)
    {
        count = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if (board[i][j] && !vis[i][j])
                {
                    queue <pair<int,int>> Q;
                    Q.push({i,j});
                    vis[i][j] = 1;
                    while (!Q.empty())
                    {
                        pair <int,int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                            if (vis[nx][ny]) continue;
                            if (!board[nx][ny])
                                board[cur.first][cur.second] = (!board[cur.first][cur.second]) ? 0 : board[cur.first][cur.second] - 1;
                            else
                            {
                                vis[nx][ny] = 1;
                                Q.push({nx,ny});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        if (count >= 2) break;
        if (!count) break;
        memset(vis, 0, sizeof(vis));
    }
    if (count) cout << t;
    else cout << 0;
}
