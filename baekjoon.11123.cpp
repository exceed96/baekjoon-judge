#include <iostream>
#include <queue>

using namespace std;

char board[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T, H, W;
    cin >> T;
    while (T--)
    {
        int count = 0;
        bool vis[102][102] = {false};
        cin >> H >> W;
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                cin >> board[i][j];
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                if (vis[i][j] || board[i][j] == '.') continue;
                else
                {
                    count++;
                    queue <pair<int,int>> Q;
                    vis[i][j] = 1;
                    Q.push({i,j});
                    while (!Q.empty())
                    {
                        pair <int,int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                            if (vis[nx][ny] || board[nx][ny] == '.') continue;
                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        cout << count << "\n";
    }
}
