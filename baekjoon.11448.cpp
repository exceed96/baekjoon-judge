#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[102][102];
bool vis[102][102];

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,-1,1,-1,1};

int T,N;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> T;
    while (T--)
    {
        queue <pair<int,int>> Q;
        int result = 0;
        memset(vis, 0, sizeof(vis));
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == 'w')
                {
                    Q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        while (!Q.empty())
        {
            pair <int,int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 8; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (board[nx][ny] == 'b' || vis[nx][ny]) continue;
                result++;
                // board[nx][ny] = 'w';
                vis[nx][ny] = 1;
                Q.push({nx,ny});
            }
        }
        cout << result << "\n";
    }
}
