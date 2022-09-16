#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, -0, -1};

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    int T;
    cin >> T;
    while (T--)
    {
        int M,N,K;
        cin >> M >> N >> K;
        int board[52][52] = {0};
        bool vis[52][52] = {false};
        for(int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        int count = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(vis[i][j] || !board[i][j]) continue;
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
                            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                            if (vis[nx][ny] || board[nx][ny] != 1) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << count << "\n";
    }
}
