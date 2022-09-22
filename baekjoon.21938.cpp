#include <iostream>
#include <queue>

using namespace std;

int board[1002][3006];
int board2[1002][1002];
bool vis[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N, M, T, count = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M * 3; j++)
            cin >> board[i][j];
    cin >> T;
    for(int i = 0; i < N; i++)
    {
        int k = 0;
        for(int j = 0; j < M * 3; j += 3)
        {
            int sum = 0;
            sum = (board[i][j] + board[i][j + 1] + board[i][j + 2]);
            if (sum / 3 >= T)
                board2[i][k] = 255;
            else
                board2[i][k] = 0;
            k++;
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (vis[i][j] || !board2[i][j]) continue;
            else
            {
                count++;
                queue <pair<int,int>> Q;
                vis[i][j] = 1;
                Q.push({i,j});
                while (!Q.empty())
                {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (vis[nx][ny] || !board2[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
    cout << count << "\n";
}
