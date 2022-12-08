#include <iostream>
#include <queue>

using namespace std;

char board[102][102];
bool vis[102][102];

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

int n,m;

int main(void)
{
    int count = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            queue <pair<int,int>> Q;
            if (vis[i][j] || board[i][j] == '.') continue;
            else
            {
                count++;
                Q.push({i,j});
                vis[i][j] = 1;
                while(!Q.empty())
                {
                    pair <int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 8; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] || board[nx][ny] == '.') continue;
                        Q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    cout << count;
}
