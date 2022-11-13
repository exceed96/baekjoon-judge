#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[102][102];
bool vis[102][102];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int W,H;

int main(void)
{
    while(1)
    {
        memset(vis, 0, sizeof(vis));
        cin >> W >> H;
        queue <pair<int,int>> Q;
        if (!W && !H)
            break;
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == 'S')
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
                if (nx < 0 || nx >= H || ny < 0 || ny >= W || board[nx][ny] == '.' || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                board[nx][ny] = 'S';
                Q.push({nx,ny});
            }
        }
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
                cout << board[i][j];
            cout << "\n";
        }
    }   
}
