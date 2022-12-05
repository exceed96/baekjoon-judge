#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[17][17];
int vis[17][17];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int T,R,C;
bool f;

int main(void)
{
    cin >> T;
    while (T--)
    {
        f = 0;
        memset(vis, -1, sizeof(vis));
        queue <pair<int,int>> Q;
        cin >> R >> C;
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == 'S')
                {
                    Q.push({i,j});
                    vis[i][j] = 0;
                }
            }
        }
        while (!Q.empty())
        {
            pair <int,int> cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (board[nx][ny] == 'X' || vis[nx][ny] >= 0) continue;
                if (board[nx][ny] == 'G')
                {
                    cout << "Shortest Path: " << vis[cur.first][cur.second] + 1 << "\n";
                    f = 1;
                    break;
                }
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                Q.push({nx,ny});
            }
            if (f)
                break;
        }
        
        if (!f)
            cout << "No Exit" << "\n";
    }
}
