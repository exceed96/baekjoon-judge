#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char board[52][52];
int vis[52][52];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int L,W;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> L >> W;
    for(int i = 0; i < L; i++)
        for(int j = 0; j < W; j++)
            cin >> board[i][j];
            
    queue <pair<int,int>> Q;
    vector <int> res;
    for(int i = 0; i < L; i++)
    {
        for(int j = 0; j < W; j++)
        {
            memset(vis, -1, sizeof(vis));
            if (board[i][j] == 'L')
            {
                Q.push({i,j});
                vis[i][j] = 0;
            }
            else continue;
            while (!Q.empty())
            {
                pair <int,int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= L || ny < 0 || ny >= W) continue;
                    if (vis[nx][ny] != -1 || board[nx][ny] == 'W') continue;
                    Q.push({nx,ny});
                    vis[nx][ny] = vis[cur.first][cur.second] + 1;
                }
            }
            int max = 0;
            for(int a = 0; a < L; a++)
            {
                for(int b = 0; b < W; b++)
                {
                    if (vis[a][b] > max)
                        max = vis[a][b];
                }
            }
            res.push_back(max);
        }
    }
    sort(res.begin(), res.end());
    cout << res[res.size() - 1];
}
