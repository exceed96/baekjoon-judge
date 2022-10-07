#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[102][102];
bool vis[102][102];
int N;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
queue <pair<int,int>> Q;

int bfs()
{
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (vis[i][j]) continue;
            else
            {
                Q.push({i,j});
                vis[i][j] = 1;
                count++;
                while (!Q.empty())
                {
                    pair <int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (vis[nx][ny] || (board[i][j] != board[nx][ny])) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
    return (count);
}

int main(void)
{
    cin.tie (0); ios_base::sync_with_stdio(0);
    int result = 0, result2 = 0;
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];
    result = bfs();
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }
    memset(vis, 0, sizeof(vis));
    result2 = bfs();
    cout << result << " " << result2 << "\n";
}
