#include <iostream>
#include <queue>

using namespace std;

int board[502][502];

int n,m;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}; //4곳의 대각선까지 추가
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    while (1)
    {
        cin >> n >> m;
        bool vis[502][502] = {false};
        if (!n && !m)
            break;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> board[i][j];
                
        int count = 0;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] || !board[i][j]) continue;
                else
                {
                    count++;
                    queue <pair<int,int>> Q;
                    vis[i][j] = 1;
                    Q.push({i,j});
                    while (!Q.empty())
                    {
                        pair<int, int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 8; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if (vis[nx][ny] || board[nx][ny] != 1) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << count << "\n";
    }
}
