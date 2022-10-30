#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[102][102];
bool vis[102][102];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N,M,K;

int main(void)
{
    int size = 0, result = 0;
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            board[i][j] = '.';
    while(K--)
    {
        int i,j;
        cin >> i >> j;
        board[i][j] = '1';
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            size = 0;
            queue <pair<int,int>> Q;
            if (vis[i][j] || board[i][j] == '.') continue;
            else
            {
                Q.push({i,j});
                vis[i][j] = 1;
                while (!Q.empty())
                {
                    size++;
                    pair <int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
                        if (vis[nx][ny] || board[nx][ny] == '.') continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
            result = max(result, size);
        }
    }
    cout << result << "\n";
}
