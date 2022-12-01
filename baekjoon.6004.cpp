#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[152][152];
int vis[152][152];

int dx[] = {2,2,-2,-2,1,1,-1,-1};
int dy[] = {1,-1,1,-1,2,-2,2,-2};

int X,Y;

int main(void)
{
    queue <pair<int,int>> Q;
    memset(vis, -1, sizeof(vis));
    cin >> Y >> X;
    for(int i = 0; i < X; i++)
    {
        for(int j = 0; j < Y; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'K')
            {
                Q.push({i,j});
                vis[i][j] = 0;
            }
        }
    }
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0 ; dir < 8; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx > X || ny < 0 || ny > Y) continue;
            if (board[nx][ny] == '*' || vis[nx][ny] >= 0) continue;
            if (board[nx][ny] == 'H')
            {
                cout << vis[cur.first][cur.second] + 1;
                return (0);
            }
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
}
