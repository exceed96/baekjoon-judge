#include <iostream>
#include <queue>

using namespace std;

char board[102][102];
int vis[102][102];

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,-1,1,1,-1};

int Y,X,s_x,s_y,result;

int main(void)
{
    queue <pair<int,int>> Q;
    cin >> Y >> X >> s_y >> s_x;
    for(int i = 1; i <= X; i++)
        for(int j = 1; j <= Y; j++)
            cin >> board[i][j];
    Q.push({X-s_x+1, s_y});
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 8; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > X || ny < 1 || ny > Y) continue;
            if (board[nx][ny] == '*' || vis[nx][ny] >= 1) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    for(int i = 1; i <= X; i++)
        for(int j = 1; j <= Y; j++)
            result = max(result, vis[i][j]);
    cout << result << "\n";
}
