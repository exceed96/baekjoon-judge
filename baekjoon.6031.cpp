#include <iostream>
#include <queue>

using namespace std;

char board[752][752];
bool vis[752][752];

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

int N,M;

int main(void)
{
    int result = 0;
    cin >> N >> M;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];
    
    queue <pair<int,int>> Q;
    
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int count = 0;
            if (board[i][j] == '*' || vis[i][j]) continue;
            else
            {
                count++;
                Q.push({i,j});
                vis[i][j] = 1;
                while (!Q.empty())
                {
                    pair <int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 8; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if (vis[nx][ny] || board[nx][ny] == '*') continue;
                        vis[nx][ny] = 1;
                        count++;
                        Q.push({nx,ny});
                    }
                }
            }
            result = max(result, count);
        }
    }
    cout << result;
}
