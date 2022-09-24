#include <iostream>
#include <queue>

using namespace std;

char board[102][102];
bool vis[102][102];
bool f;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) 
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N,M, result_w = 0, result_b = 0;
    cin >> N >> M;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (vis[i][j] || !board[i][j]) continue;
            else
            {
                if (board[i][j] == 'W')
                    f = false;
                else
                    f = true;
                queue <pair<int,int>> Q;
                vis[i][j] = 1;
                Q.push({i,j});
                int area = 0;
                while (!Q.empty())
                {
                    area++;
                    pair <int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if (vis[nx][ny] || !board[nx][ny] || board[nx][ny] != board[cur.first][cur.second]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                if(f)
                    result_b += area * area;
                else
                    result_w += area * area;
            }
        }
    }
    cout << result_w << " " << result_b;
}
