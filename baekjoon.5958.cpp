#include <iostream>
#include <queue>

using namespace std;

char board[1002][1002];
bool vis[1002][1002];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N,count;

queue <pair<int,int>> Q;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];
            
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (board[i][j] == '.' || vis[i][j]) continue;
            else
            {
                count++;
                Q.push({i,j});
                vis[i][j] = 1;
                while(!Q.empty())
                {
                    pair <int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (board[nx][ny] == '.' || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
    cout << count;
}
