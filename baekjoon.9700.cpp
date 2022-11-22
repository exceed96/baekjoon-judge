#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[42][42];
bool vis[42][42];

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

int N;

int main(void)
{
    int c = 1;
    while (cin >> N)
    {
        int count = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> board[i][j];
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                queue <pair<int,int>> Q;
                if (board[i][j] == '0' || vis[i][j]) continue;
                else
                {
                    count++;
                    Q.push({i,j});
                    vis[i][j] = 1;
                    while (!Q.empty())
                    {
                        pair <int,int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 8; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (board[nx][ny] == '0' || vis[nx][ny]) continue;
                            Q.push({nx,ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        cout << "Case #" << c << ": " << count << "\n";
        c++;
    }
}
