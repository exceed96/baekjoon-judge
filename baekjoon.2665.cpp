#include <iostream>
#include <queue>

using namespace std;

char board[52][52];
int vis[52][52];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int n;

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            vis[i][j] = 987654321;
        }
    }
    queue <pair<int,int>> Q;
    Q.push({0,0});
    vis[0][0] = 0;
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (board[nx][ny] == '1')
                {
                    if (vis[nx][ny] > vis[cur.first][cur.second])
                    {
                        vis[nx][ny] = vis[cur.first][cur.second];
                        Q.push({nx,ny});
                    }
                }
                else
                {
                    if (vis[nx][ny] > vis[cur.first][cur.second] + 1)
                    {
                        vis[nx][ny] = vis[cur.first][cur.second] + 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
    cout << vis[n - 1][n - 1];
}
