#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[1002][1002];
int vis[1002][1002];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int X,Y,N;
queue <pair<int,int>> Q;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> X >> Y >> N;
    memset(board, '.', sizeof(board));
    memset(vis, -1, sizeof(vis));
    board[X + 500][Y + 500] = 'B';
    board[500][500] = '*'; vis[500][500] = 0; Q.push({500,500});
    
    for(int i = 0; i < N; i++)
    {
        int a,b;
        cin >> a >> b;
        board[a + 500][b + 500] = 'M';
    }
    
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= 1000 || ny < 0 || ny >= 1000) continue;
            if (board[nx][ny] == 'M' || vis[nx][ny] >= 0) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    cout << vis[X + 500][Y + 500];
}
