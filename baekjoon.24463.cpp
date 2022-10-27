#include <iostream>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[2003][2003];
int vis[2003][2003];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int N,M,count,count_m;
queue <pair<int,int>> Q;
queue <pair<int,int>> Q_m;
bool f;

int bfs()
{
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir ++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] != -1 || board[nx][ny] == '+') continue;
            if (board[nx][ny] == '.' && (!nx || nx == N - 1 || !ny || ny == M - 1))
            {
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                count = vis[nx][ny];
                Q_m.push({nx,ny});
                board[nx][ny] = '@';
                while (!Q.empty())
                    Q.pop();
                return (count);
            }
            Q.push({nx,ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }
}

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M;
    memset(vis, -1, sizeof(vis));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if ((!i || i == N - 1 || !j || j == M - 1) && !f)
            {
                if (board[i][j] == '.')
                {
                    f = 1;
                    Q.push({i,j});
                    vis[i][j] = 0;
                }
            }
        }
    }
    
    count_m = bfs();
    while (count_m--)
    {
        pair <int,int> cur = Q_m.front(); Q_m.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] == count_m)
            {
                board[nx][ny] = '@';
                Q_m.push({nx,ny});
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (board[i][j] == '@')
                board[i][j] = '.';
            else if (board[i][j] == '.')
                board[i][j] = '@';
            cout << board[i][j];
        }
        cout << "\n";
    }
}
