#include <iostream>
#include <queue>

using namespace std;

char board[102][102];
bool vis[102][102];

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

int N,M, count;

int main(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            queue <pair<int,int>> Q;
            if (board[i][j] == '.' || vis[i][j]) continue;
            else
            {
                count++;
                vis[i][j] = 1;
                Q.push({i,j});
                while (!Q.empty())
                {
                    pair <int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 8; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (board[nx][ny] == '.' || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
    cout << count;
}
