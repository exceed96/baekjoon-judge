#include <iostream>
#include <queue>

using namespace std;

char board[502][502];
int vis[502][502];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int n,m;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];
    int start_x, start_y, exit_x, exit_y;
    cin >> start_x >> start_y >> exit_x >> exit_y;
    queue <pair<int,int>> Q;
    board[start_x][start_y] = 'X';
    vis[start_x][start_y] = 1;
    Q.push({start_x, start_y});
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if ((board[nx][ny] == 'X' && (nx != exit_x || ny != exit_y))) continue;
            if (nx == exit_x && ny == exit_y && board[nx][ny] == 'X')
            {
                cout << "YES" << "\n";
                return (0);
            }
            Q.push({nx,ny});
            board[nx][ny] = 'X';
            vis[nx][ny]++;
        }
    }
    cout << "NO" << "\n";
}
