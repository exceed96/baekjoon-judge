#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[102][102];

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};
int N, M;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    while (1)
    {
        bool vis[102][102] = {false};
        int count = 0;
        cin >> N >> M;
        if (!N) break;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> board[i][j];
                
        queue <pair<int,int>> Q;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if (vis[i][j] || board[i][j] == '*') continue;
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
                            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                            if(vis[nx][ny] || board[nx][ny] != '@') continue;
                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        cout << count << "\n";
    }
}
