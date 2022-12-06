#include <iostream>
#include <queue>

using namespace std;

char board[1002][1002];
bool vis[1002][1002];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int M,N;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> M >> N;
    queue <pair<int,int>> Q;
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (!i && board[i][j] == '0')
            {
                Q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (board[nx][ny] == '1' || vis[nx][ny]) continue;
            if (nx == M - 1)
            {
                cout << "YES";
                return (0);
            }
            Q.push({nx,ny});
            vis[nx][ny] = 1;
        }
    }
    cout << "NO";
}
