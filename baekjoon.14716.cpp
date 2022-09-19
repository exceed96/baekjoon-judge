#include <iostream>
#include <queue>

using namespace std;

int board[252][252];
bool vis[252][252];
int dx[8] = {1,0,-1,0,1, 1, -1, -1};
int dy[8] = {0,1,0,-1,1, -1, 1, -1};

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N, M, count = 0;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (vis[i][j] || !board[i][j]) continue;
            else
            {
                count++;
                queue <pair<int,int>> Q;
                vis[i][j] = 1;
                Q.push({i,j});
                while (!Q.empty())
                {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 8; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
    cout << count << "\n";
}
